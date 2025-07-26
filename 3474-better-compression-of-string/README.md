<h2><a href="https://leetcode.com/problems/better-compression-of-string">3474. Better Compression of String</a></h2><h3>Medium</h3><hr><p>You are given a string <code>compressed</code> representing a compressed version of a string. The format is a character followed by its frequency. For example, <code>&quot;a3b1a1c2&quot;</code> is a compressed version of the string <code>&quot;aaabacc&quot;</code>.</p>

<p>We seek a <strong>better compression</strong> with the following conditions:</p>

<ol>
	<li>Each character should appear <strong>only once</strong> in the compressed version.</li>
	<li>The characters should be in <strong>alphabetical order</strong>.</li>
</ol>

<p>Return the <em>better compression</em> of <code>compressed</code>.</p>

<p><strong>Note:</strong> In the better version of compression, the order of letters may change, which is acceptable.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">compressed = &quot;a3c9b2c1&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;a3b2c10&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>Characters &quot;a&quot; and &quot;b&quot; appear only once in the input, but &quot;c&quot; appears twice, once with a size of 9 and once with a size of 1.</p>

<p>Hence, in the resulting string, it should have a size of 10.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">compressed = &quot;c2b3a1&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;a1b3c2&quot;</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">compressed = &quot;a2b4c1&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;a2b4c1&quot;</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= compressed.length &lt;= 6 * 10<sup>4</sup></code></li>
	<li><code>compressed</code> consists only of lowercase English letters and digits.</li>
	<li><code>compressed</code> is a valid compression, i.e., each character is followed by its frequency.</li>
	<li>Frequencies are in the range <code>[1, 10<sup>4</sup>]</code> and have no leading zeroes.</li>
</ul>
