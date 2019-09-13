Complexity

Red Black Trees
Insertion of an element in the tree takes O(log N) time because it is a form of binary search tree and they have a height of O(log N) where N is the number of nodes. As the insertion involves only one for loop, so it takes that many iteration as the height.
The recoloring involves O(1) as it involves only the color changing of nodes and reconstruction involves O(1). In the worst-case, the recoloring that is done during insert is O(log N) ( = time for one recoloring * max number of recolorings done = O(1) * O(log N) ).
The total time for insert is O(log N).
Similarly, for deletion as well as searching, total time is O(log N)

AVL Trees
Here also, insertion takes O(log N) time because AVL tree is also a form of a BST.
In the second step that involves reconstruction, where the time is directly proportional to the path it covers on the way back. So best case is O(1) and the worst case is O(log N).


Comparison

Here we can see that for all the trees, time required for insertion, searching as well as deletion is O(log N).
Now the question that arises is that, how are these trees different from each other.
Mathematically all the trees mentioned above are very similar. The real scenario where the differences arise is performance.

The real difference between Red black and AVL occurs in different operations. If the task involves multiple lookups into a tree for finding a key, then AVL is better than RB. The reason behind is that the path from root to leaf in an AVL tree is at most ~1.44 lg(n+2), whereas in Red Black trees it is ~2 lg(n+1).
So clearly, for traversing, AVL is preferred due its shorter path.

But if the task involves multiple insertions and deletions, RB is preferred over AVL trees. The insertion causes a number of rotations in AVL tree whereas in RB tree, insertion requires O(1) time. AVL trees are hence more rigidly balanced that RB trees.

The AVL or RB tress are not meant for storing large data as they use dynamic memory allocation.



Conclusion

AVL tree is preferred when there are more look ups into the tree, and if there more insertions or deletions, Red Black is preferred.

