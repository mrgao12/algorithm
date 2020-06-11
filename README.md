[TOC]

## 一、线性表

## 二、链表
单向链表结构定义如下：
```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```
#### 1、翻转链表
[leetcode206](https://leetcode-cn.com/problems/reverse-linked-list/)
***
- 递归解法
设置递归函数的返回值为翻转后链表的首节点
递归终止条件为空节点或节点长度为1
实现代码如下：
```cpp
ListNode* reverse ( ListNode* head ) {
    if ( ! head || head->next == NULL ) return head;

    ListNode* newHead = reverse ( head->next );
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
```

- 非递归解法
尾插法，将原本的节点通过尾插法不断的加入新节点
实现代码如下：
```cpp
ListNode* reverse ( ListNode* head ) {
    if ( ! head || head->next == NULL )
    ListNode* pre = NULL;

    while ( head ) {
        ListNode* next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
```

### 2、翻转链表的前n个元素
同翻转整个链表相同，只是要记录第n+1个元素，然后将head->next接入第n+1个元素

- 递归解法
```cpp
ListNode* successor = NULL;
ListNode* reverseNList ( ListNode* head, int n ) {
    if ( n == 1 ) {
        successor = head->next;
        return head;
    }

    ListNode* newHead = reverseNList ( head->next, n-1 );
    head->next->next = head;
    head->next = successor;

    return newHead;
}
```

### 3、翻转链表的某一段元素（从m开始到n）
[leetcode92](https://leetcode-cn.com/problems/reverse-linked-list-ii/)
***
减治问题，如果m=1则问题等价于翻转链表的前n个元素

- 递归解法
```cpp
ListNode* successor = NULL;
ListNode* reverseNList ( ListNode* head, int n ) {
    if ( n == 1 ) {
        successor = head->next;
        return head;
    }

    ListNode* newHead = reverseNList ( head->next, n-1 );
    head->next->next = head;
    head->next = successor;

    return newHead;
}

ListNode* reverseBetween ( ListNode* head, int m, int n ) {
    if ( m == 1 ) return reverseNList ( head, n );
    head->next = reverseBetween ( head->next, m-1, n-1 );
    return head;
}
```

### 4、查找链表中点
快慢指针法，慢指针一次移动一步，快指针一次移动两步

```cpp
ListNode* midst ( ListNode* head ) {
    ListNode* slow = head;
    ListNode* fast = head;

    while ( fast && fast->next ) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

### 5、合并两个有序链表
[leetcode21](https://leetcode-cn.com/problems/merge-two-sorted-lists/)
***
设置一个头指针，随后以此将两个链表中元素较小者加于到该指针的尾部并移动相应的指针。

- 递归解法
```cpp
ListNode* mergeSortedList ( ListNode* l1, ListNode* l2 ) {
    if ( ! l1 ) return l2;
    else if ( ! l2 ) return l1;
    else if ( l1->val <= l2->val ) {
        l1->next = mergeSortedList ( l1->next, l2 );
        return l1;
    } else {
        l2->next = mergeSortedList ( l1, l2->next );
        return l2;
    }
}
```

- 非递归解法
```cpp
ListNode* mergeSortedList ( ListNode* l1, ListNode* l2 ) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* head = dummyHead;

    while ( l1 && l2 ) {
        if ( l1->val <= l2->val ) { head->next = l1; l1 = l1->next; head = head->next; }
        else { head->next = l2; l2 = l2->next; head = head->next; }
    }
    head->next = ( l1 ? l1 : l2 );

    return dummyHead->next;
}
```

### 6、有序链表去重
[leetcode83](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)
***
有序链表的重复元素必然紧邻，考察链表中相邻的元素，若相同则删除其中一个

```cpp
ListNode* deleteDuplicates ( ListNode* head ) {
    if ( ! head || ! head->next ) return head;
    ListNode* p = head; ListNode* q;

    while ( q = p->next ) {
        if ( p->val == q->val ) { p->next = q->next; delete q; }
        else p = p->next;
    }
}
```

### 7、寻找链表中是否有环
[leetcode141](https://leetcode-cn.com/problems/linked-list-cycle/)
***
赛跑问题，设置快、慢指针，如果有环那么快指针会跑到慢指针后面，如果没环快指针会先到达空指针。
假设快指针的速度为$v_1$，慢指针的速度为$v_2$。环的长度为$s$，由于两者并不是同时在环的起点开始跑的，所以两者都进入环时会有一个位移差$d$，则$$(v_1 - v_2)t = s-d$$由于$t$一定要是整数，所以设置两者速度差为1，即快指针一次移动2个，慢指针一次移动1格
```cpp
bool hasCycle ( ListNode* head ) {
    if ( ! head || ! ( head->next ) ) return false;

    ListNode* fast = head; ListNode* slow = head;

    while ( fast && fast->next ) {
        slow = slow->next;
        fast = fast->next->next;

        if ( slow == next ) return true;
    }

    return false;
}
```

### 8、寻找链表中是否有环并找出快慢指针的交点
[leetcode142](https://leetcode-cn.com/problems/linked-list-cycle-ii/)
***
![pic1](https://pic.leetcode-cn.com/99987d4e679fdfbcfd206a4429d9b076b46ad09bd2670f886703fb35ef130635-image.png)

$F+a$为慢指针所走过的距离，$F+a+b+a$为快指针走过的距离，显然有$$2(F+a) = F+a+b+a$$，由此可以推出$F=b$。

```cpp
ListNode* detectCycle ( ListNode* head ) {
    if ( ! head || ! ( head->next ) ) retur NULL;
    ListNode* fast = head;
    ListNode* slow = head;

    while ( fast && fast->next ) {
        slow = slow->next;
        fast = fast->next->next;

        if ( slow == fast ) break;
    }

    if ( ! fast || ! fast->next ) return NULL;

    slow = head;

    while ( slow != fast ) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
```

### 9、链表的归并排序
[leetcode148](https://leetcode-cn.com/problems/sort-list/)
***
归并排序属于分而治之的算法，分的过程采用寻找中点算法，合的过程采用有序链表的合并算法
```cpp
// 寻找链表中点算法
ListNode* midst ( ListNode* head ) {
    ListNode* slow = head; ListNode* fast = head;

    while ( fast && fast->next ) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// 合并两个有序链表
ListNode* merge ( ListNode* p, ListNode* q ) {
    if ( ! p ) return q;
    else if ( ! q ) return p;
    else if ( p->val <= q->val ) {
        p->next = merge ( p->next, q );
        return p;
    } else {
        q->next = merge ( p, q->next );
        return q;
    }
}

// 归并排序算法
void mergeSort ( ListNode*& head ) {
    if ( !head || ! head->next ) return;

    ListNode* mi = midst ( head );
    ListNode* p = head; ListNode* q = mi->next;

    mi->next = NULL;

    mergeSort ( p ); mergeSort ( q );

    head = merge ( p, q );
}
```

### 10、链表的插入排序
[leetcode147](https://leetcode-cn.com/problems/insertion-sort-list/)
***
插入排序将整个序列分为两个部分，前端为有序，后端为无序，不断的将无序中的第一个元素加入有序
![pic2](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)
```cpp
ListNode* search ( ListNode* head, int n, int e ) {
    ListNode* p = head; ListNode* q;

    while ( 0 <= n-- ) {
        q = p;
        if ( e <= ( p = p->next )->val ) break;
    }

    return q;
}

ListNode* insertionSortList ( ListNode* head ) {
    if ( ! head || head->next == NULL ) return head;
    ListNode* dummyHead = new ListNode ( 0 );
    dummyHead->next = head;
    
    ListNode* p = dummyHead; ListNode* q;
    int r = 0;

    while ( ( q = p->next ) != NULL ) {
        ListNode* pre = search ( dummyHead, r, q->val );
        if ( pre->next == q ) p = q;
        else {
            p->next = q->next;
            q->next = pre->next;
            pre->next = q;
        }
        r++;
    }

    return dummyHead->next;
}
```

### 11、判断链表是否回文
[leetcode234](https://leetcode-cn.com/problems/palindrome-linked-list/)
***
- 方法一：新建一个向量或数组，将链表存储到数组中去，然后对数组判断书否回文

- 方法二：使用快慢指针法找到链表中点，将链表分为两个部分，对后半部分进行翻转，然后判断是否为回文

- 方法三：递归判断，递归到链表尾部，设置front指向链表首部，每次回溯时，front后移并判断两个元素是否相等

方法三代码如下：
```cpp
class Solution {
    private:
        ListNode* front;
    public:
        bool recursion ( ListNode* cur ) {
            if ( cur ) {
                if ( ! recursion ( cur->next ) ) return false;
                if ( front->val != cur->val ) return false;
                front = front->next;
            }
            return true;
        }
        bool isPalindrome(ListNode* head) {
            front = head;
            return recursion ( head );
        }
};
```

### 12、寻找链表的交点
[leetcode160](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)
***
![](https://pic.leetcode-cn.com/e0efdd908a8941e3c53a68a6049d88c437b8299e48540a772ab091b86695d981-image.png)
如图所示，每个节点走完自己的路时走对方的路，它们一定会到达同一个节点，如果是有交点的则相遇在交点处，如果没有则同时到达NULL节点。$$a+c+b=b+c+a$$
```cpp
ListNode *getIntersectionNode ( ListNode *headA, ListNode *headB ) {
    ListNode* a = headA; ListNode* b = headB;

    while ( a != b ) {
        a = a ? headB : a->next;
        b = b ? headA : b->next;
    }
    return a;
}
```

## 三、栈

## 四、队列

## 五、树

## 六、图
### 1、BFS/DFS
[leetcode04.01](https://leetcode-cn.com/problems/route-between-nodes-lcci/)
***
不同遍历算法之间的区别主要在于在遍历的每一步迭代过程中按照何种策略选取下一个待访问节点，一般待访问节点一定是从已访问节点的邻居中选取，当然一个节点的邻居可能有多个，一般不考虑邻居之间的次序。这里所考虑的策略是当有多个已经被访问的节点时，优先选取哪个节点的邻居作为下一次待访问的节点。
BFS：越早被访问的节点，其邻居越优先被选取
```cpp
class Solution {
    public:
        void bfs ( bool& flag, vector< bool >& status, int start, int target, vector< vector< int > >& adjancey ) {
            queue< int > Q; Q.push ( start );

            while ( ! Q.empty() ) {
                int v = Q.front(); Q.pop(); status[v] = 1;
                for ( auto u : adjancey[v] ) {
                    if ( u == target ) { flag = true; return; }
                    if ( status[u] == 0 ) Q.push ( u );
                }
            }
        }
        
        bool findWhetherExistsPath( int n, vector< vector< int > >& graph, int start, int target ) {
            bool flag = false;
            vector< vector< int > > adjancey ( n );
            vector< bool > status ( n, 0 );

            for ( auto edge : graph ) {
                adjancey[edge[0]].push_back ( edge[1] );
            }

            bfs ( flag, status, start, target, adjancey );
            return flag;
        }
};
```
DFS：优先选取最晚被访问的节点的邻居作为下一步待访问节点
```cpp
class Solution {
    public:
        void dfs ( bool& flag, vector< bool >& status, int start, int target, vector< vector< int > >& adjancey ) {
            status[start] = 1;
            for ( auto u : adjancey[start] ) {
                if ( u == target ) { flag = true; return; }
                if ( status[u] == 0 ) dfs ( flag, status, u, target, adjancey );
            }
        }

        bool findWhetherExistsPath( int n, vector< vector< int > >& graph, int start, int target ) {
            bool flag = false;
            vector< vector< int > > adjancey ( n );
            vector< bool > status ( n, 0 );

            for ( auto edge : graph ) {
                adjancey[edge[0]].push_back ( edge[1] );
            }

            dfs ( flag, status, start, target, adjancey );
            return flag;
        }
};
```
### 2、拓扑排序
[leetcode207](https://leetcode-cn.com/problems/course-schedule/)
***
    你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

    在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

    给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

拓扑排序问题，针对于有向无环图，作为偏序关系必然存在极值（不唯一），因此从两个方面考虑，不断取出极大值和不断取出极小值
- 零入度算法
既然是有向无环图就一定存在入度为零的点（可能不唯一），因此考虑每次从图中删除一个入度为0的顶点，随着它的删除某些顶点的入度也会减少，因此每时每刻都存在入度为0的顶点，知道整个图被删除完毕，这样一个过程中顶点的删除次序就是一个拓扑排序序列。
```cpp
class Solution {
    public:
        bool canFinish ( int numCourses, vector< vector< int > >& prerequisites ) {
            vector< int > inDegree ( numCourses, 0 );
            vector< vector< int > > adjeancy ( numCourses );
            for ( auto edge : prerequisites ) {
                adjeancy[edge[0]].push_back ( edge[1] );
                inDegree[edge[1]]++;
            }

            queue< int > Q;

            for ( int i = 0; i < inDegree.size(); i++ ) {
                if ( ! inDegree[i] ) Q.push ( i );
            }

            while ( ! Q.empty() ) {
                int i = Q.top(); Q.pop(); numCourses--;
                for ( auto j : adjeancy[i] ) {
                    inDegree[j]--;
                    if ( inDegree[j] == 0 ) Q.push ( j );
                }
            }

            return !numCourses;
        }
};
```
- 零出度算法
同样的，DAG也一定存在出度为0的顶点，可以同样考虑上面的算法，但根据DFS的流程，最先完成访问的顶点一定是出度为0的顶点，随后它访问完毕，逻辑上等效为它删除了，因此这会改变某些顶点的出度，所以DFS遍历次序的一个逆序过程就是一个拓扑排序流程。
```cpp
class Solution {
    public:
        bool canFinish ( int numCourses, vector< vector< int > >& prerequisites ) {
            vector< vector< int > > adjacency ( numCourses );
            for ( auto edge : prerequisites ) {
                adjacency[edge[0]].push_back ( edge[1] );
            }
            int v = 0, s = v;
            vector< int >status ( numCourses, 0 );
            do {
                if ( status[v] == 0 ) {
                    if ( ! dfs ( v, adjacency, status ) ) return false;
                }
            } while ( s != ( v = ( ++v % numCourses ) ) );

            return true;
        }

        bool dfs ( int v, vector< vector< int > > const& adjacency, vector< int >& status ) {
            status[v] = 1;

            for ( auto u : adjacency[v] ) {
                if ( status[u] == 0 ) {
                    status[u] = 1;
                    if ( ! dfs ( u, adjacency, status ) ) return false;
                } else if ( status[u] == 1 ) return false;
            }
            status[v] = 2; return true;
        }
};
```

## 七、二叉搜索树
### 1、判断一棵二叉树是否为平衡二叉树（AVL）
[leetcode110](https://leetcode-cn.com/problems/balanced-binary-tree/)
***

- 方法一：自上而下递归的判断每个节点的平衡因子是否满足要求（0，-1，+1），终止条件：若该节点不平衡则立即返回错误
![](https://pic.leetcode-cn.com/Figures/110/topDown-0.png)
时间复杂度为$O(nlogn)$，因为平衡二叉树的树高不超过$O(logn)$，因此在每个节点处树高判断不超过$O(logn)$，总计不超过$O(nlogn)$
```cpp
class Solution {
    public:
        int height ( TreeNode* p ) {
            if ( ! p ) return -1;
            return 1 + max ( height ( p->left ), height ( p->right ) );
        }
        bool isBalanced ( TreeNode* root ) {
            if ( ! root ) return true;
            if ( abs ( height ( root->left ) - height ( root->right ) ) > 1 ) return false;
            return ( isBalanced ( root->left ) && isBalanced ( root->right ) );
        }
};
```

- 方法二：自下而上的判断
方法一存在大量冗余计算，改为自下而上的判断，如果子树是平衡的返回其高度算父节点的平衡因子
```cpp
class Solution {
    public:
        bool core ( TreeNode* p, int& height ) {
            if ( ! p ) {
                height = -1;
                return true;
            }
            
            int lh, rh;
            if ( core ( p->left, lh ) && core ( p->right, rh ) && abs ( lh - rh ) < 2 ) {
                height = max ( lh, rh ) + 1;
                return true;
            }
            return false;
        }
        bool isBalanced ( TreeNode* root ) {
            int height;
            return core ( root, height );
        }
};
```

### 2、寻找两个节点的最近公共祖先
[leetcode235](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
***

借助二叉搜索树的特性进行减治，中序遍历序列一定非减，根节点为非减序列的中位数。
如果两个数一个大于中位数一个小于，那么一定在两棵不同的子树上，因此其最近的根节点就是当前树的根节点。
否则如果两个数都小于根节点的数，缩小规模至左子树，反之右子树。

```cpp
class Solution {
    public:
        TreeNode* lowestCommonAncestor ( TreeNode* root, TreeNode* p, TreeNode* q ) {
            while ( true ) {
                if ( p->val < root->val && q->val < root->val ) root = root->left;
                else if ( p->val > root->val && q->val > root->val ) root = root->right;
                else return root;
            }
        }
};
```

### 2、统计二叉搜索树的种类
[leetcode96](https://leetcode-cn.com/problems/unique-binary-search-trees/)
***

经典的卡特兰树
设$G(n)$表示的是$n$个节点一共可以组成多少种二叉搜索树，二叉树包含左子树和右子树，也就是说$G(n) = G(n_左)*G(n_右)$，左子树的节点个数可以是0到n-1，对应的右子树的规模就是从n-1到0。
$$G(n) = \sum_{i=1}^{n}G(i-1)*G(i)$$
特别的，显然可以知道$G(0) = G(1) = 1$。
```cpp
class Solution {
    public:
        int numTrees ( int n ) {
            vector<int>dp ( n + 1, 0 );
            dp[0] = 1; dp[1] = 1;

            for ( int i = 2; i <= n; i++ ) {
                for ( int j = 1; j <= i; j++ ) {
                    dp[i] += dp[j-1] * dp[i-j];
                }
            }

            return dp[n];
        }
};
```

### 2、枚举二叉搜索树的种类
[leetcode95](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/submissions/)
***
按照上一题的思路，递归构造二叉搜索树，若共有n个节点，则根节点可以是$1,2,3,...,n$，每当根节点选定，左子树和右子树的根节点选择范围也就固定了，递归的构造出整棵树。
![](https://pic.leetcode-cn.com/f709dff506c20ac970d4cd7ace0436aafca7828c67b510cdbaaa60d54f5479b3-image.png)

```cpp
class Solution {
    public:
        vector<TreeNode*> core ( int start, int end ) {
            vector<TreeNode*> treeArray;
            if ( end < start ) {
                treeArray.push_back ( ( TreeNode* ) NULL );
                return treeArray;
            }
            for ( int i = start; i <= end; i++ ) {
                vector<TreeNode*> left = core ( start, i - 1 );
                vector<TreeNode*> right = core ( i + 1, end );

                for ( auto lt : left ) {
                    for ( auto rt : right ) {
                        TreeNode* root = new TreeNode ( i );
                        root->left = lt;
                        root->right = rt;
                        treeArray.push_back ( root );
                    }
                }
            }
            return treeArray;
        }
        vector<TreeNode*> generateTrees ( int n ) {
            if ( n == 0 ) return vector<TreeNode*>();
            return core ( 1, n );
        }
};
```

### 2、验证一棵树是否为二叉搜索树
[leetcode98](https://leetcode-cn.com/problems/validate-binary-search-tree/)
***
- 方法1：利用二叉搜索树的性质，左子树必定小于根节点元素，右子树必定大于根节点，因此可以通过自下而上的判断左右子树是否为二叉搜索树并返回左子树的最大值以及右子树的最小值是否符合与根节点的大小关系来判别。
```cpp
class Solution {
    public:
        bool core ( TreeNode* x, int& maxVal, int& minVal ) {
            if ( ! ( x->left ) && ! ( x->right ) ) {
                maxVal = x->val;
                minVal = x->val;
                return true;
            }
            int lmax, lmin, rmax, rmin;
            bool l = ( ! x->left ) || ( core ( x->left, lmax, lmin ) && lmax < x->val );
            bool r = ( ! x->right ) || ( core ( x->right, rmax, rmin ) && x->val < rmin );
            if ( l && r ) {
                maxVal = x->right ? rmax : x->val;
                minVal = x->left ? lmin : x->val;
                return true;
            }

            return false;
        }
        bool isValidBST ( TreeNode* root ) {
            if ( ! root ) return true;
            int maxVal, minVal;
            return core ( root, maxVal, minVal );
        }
};
```

- 方法2：二叉搜索树的特性决定了二叉搜索树的中序遍历必然是一个非减序列，因此通过中序遍历二叉搜索树并判断是否非减来判别
```cpp
class Solution {
    public:
        void travInorder ( TreeNode* root, vector<int>& range ) {
            if ( ! root ) return;

            travInorder ( root->left, range );
            range.push_back ( root->val );
            travInorder ( root->right, range );
        }
        bool isValidBST ( TreeNode* root ) {
            vector<int> range;
            travInorder ( root, range );

            for ( int i = 1; i < range.size(); i++ ) {
                if ( range[i] <= range[i-1] ) return false;
            }
            return true;
        }
};
```
