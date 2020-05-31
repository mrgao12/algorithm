
***
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

### 2、翻转链表的某一段元素（从m开始到n）
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

### 3、查找链表中点
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

### 4、合并两个有序链表
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

### 5、有序链表去重
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

### 6、寻找链表中是否有环
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

### 7、寻找链表中是否有环并找出快慢指针的交点
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

### 8、链表的归并排序
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

### 9、链表的插入排序