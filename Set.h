/**
 * Using Binary search tree to implement Set internally(i.e. internal structure is a BST), and so does Map.
 * In fact, Set and Map make no difference in internal implementation.
 * Also, HashSet and HashMap make no difference in interanl implementation.
 * The only difference is the corresponding TreeNode structureand HashNode strcuture.
 * Both Map element and HashMap element are a pair, thus:
 * 
 * Set:                             Map:
 * int data                         int key      string key     string key     我们进一步可以使用模板template,搞一个或多个模板参数,来让basic element里的数据类型不局限于int
 * TreeNode *leftchild              int value    string value   int value
 * TreeNode *rightchild             TreeNode *leftchild
 *                                  TreeNode *rightchild
 * 
 * HashSet:                         HashMap
 * int data                         int key
 * HashNode *next                   int value
 *                                  HashNode *next
 * 所以: 实现了Set只需要改改TreeNode就变成了Map. 二叉搜索树之前实现过了(印象中是)，这里就不再重复了，所以就不再在这里实现Set和Map了。
 *       实现了HashSet只需要改改HashNode就变成了HashMap. 二者之中，我们挑HashSet来实现。
 *       Set到HashSet或者Map到HashMap则是从二叉搜索树BST改成哈希形成的哈希表(hash table --> buckets(vector, array) whose element is a LinkedList).
 *       By the way, hash table is an super upgrade version than lookup table in chapter 15.2.
 * 
 * 书本的讲课思路是引人入胜地将算法复杂度逐步降低：
 * StringMap ---> SortedMap ---> Map ---> HashMap
 *                SortedSet ---> Set ---> HashSet
 * SortedMap or SortedSet 一直维持顺序(插入排序),通过这种方式，可以将get的复杂度降低到O(logN),但是put的复杂度依旧是O(N).
 * Of course, we can design 'StringSet', but given that StringMap is merely used to let us to know why should design Map(BST internally)
 * and why should design HashMap. Both reason is that we want to push the limit of the complexity of our algorithm in add, contains, remove to O(1).
 * It turns out we finally achieve our ojective by design these new data structures step by step.
 * 
*/