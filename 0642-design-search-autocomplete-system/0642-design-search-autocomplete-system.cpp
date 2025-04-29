
class AutocompleteSystem {
    
    class TrieNode{
        public:
            unordered_map<char, TrieNode*> child;
            string str;
            int count;
            TrieNode(): str(""), count(0) {}
    };
    
    void insert(string& s, TrieNode* root, int times){
        TrieNode* curr = root;
        for (int i=0;i<s.size();i++){
            if (!curr->child.count(s[i]))
                curr->child[s[i]] = new TrieNode();
            curr = curr->child[s[i]];
        }
        curr->count += times;
        curr->str = s;
    }
    
public:
    void dfs(TrieNode* temp){
        if (temp->str != "") q.push({temp->str, temp->count});
        
        for (auto& ele: temp->child){
            dfs(ele.second);
        }
    }
    
    struct comp{
        bool operator() (pair<string, int>& a, pair<string, int>& b){
            return a.second<b.second || a.second==b.second && a.first>b.first;
        }
    };
    
    priority_queue<pair<string, int>, vector<pair<string, int> >, comp> q;
        
    TrieNode* root, *curr;
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        for (int i=0;i<sentences.size();i++){
            insert(sentences[i], root, times[i]);
        }
        curr = root;
    }
    
    
    string s="";
    vector<string> input(char c) {
        q = priority_queue<pair<string, int>, vector<pair<string, int> >, comp>();
        if (c=='#'){
            insert(s, root, 1);
            s="";
            curr = root; //start searching from the beginning node for the next sentence
            return {};
        }
        s += c;
        if (curr && curr->child.count(c)){
            curr = curr->child[c];
        }else{
            curr = NULL; //curr node is null so empty result for any further characters in current input 
            return {};
        }
        
        if (curr->str != "") q.push({curr->str, curr->count});
        for (auto& ele: curr->child){
            dfs(ele.second);
        }
        
        vector<string> res;
        while (!q.empty() && res.size()<3){
            res.push_back(q.top().first);
            q.pop();
        }
        
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */