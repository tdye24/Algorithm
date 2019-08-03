# Algorithm

Algorithm 算法设计与分析

#### 一、动态规划

##### 1.单调队列优化多重背包

> 原始状态转换方程：

$$
c[i]  =  min(s[i], \quad j/v[i])
$$

$$
f[i][j] = max(f[i-1][j-k*v[i]]+k*w[i]) ,0<=k<=c[i]
$$

- v[i]：每件第i类物品的耗费
- s[i]：第i类物品总数
- w[i]：每件第i类物品的收益

> *优化：*

$$
a = j/v[i],\quad b=j \% v[i]
$$

$$
j = a * v[i] + b
$$

$$
f[i][j] = max(f[i-1][(a-k)*v[i]+b]+k*w[i])
$$

$$
k' = a - k
$$

$$
f[i][j] = max(f[i-1][k'*v[i]+b]-k'*w[i]+a*w[i])， a-c[i] <= k <= a
$$

- k'：第i类物品还有多少件未装进背包

可以发现：
$$
f[i-1][k'*v[i]+b] - k'*w[i]+a*w[i]
$$
只与 k' 有关，而这个 k '是一段连续的。我们要做的就是求出
$$
f[i-1][k'*v[i]+b] - k'*w[i]
$$
在 k 取可行区间内时的最大值。这就可以使用单调队列优化。

> Code

```java
import java.util.*;
import java.io.*;
public class Knapsack {
	public static final int MAX = 20024;
	static int[] dp = new int[MAX];
	static int[] f = new int[MAX];
	static int[] monotone_queue = new int[MAX];
	static int[] S = new int[MAX];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		int V = sc.nextInt();
		for(int i=1; i<=N; i++) {
			int w, v, s;
			v = sc.nextInt();
			w = sc.nextInt();
			s = sc.nextInt();
			for(int j=0; j<v; j++) {
				int head = 1, tail = 0;
				for(int k=0; k*v+j <= V; k++) {
					int pro = f[k*v+j] - k * w;
					while(head <= tail && pro >= monotone_queue[tail]) 
						tail--;
					S[++tail] = k;
					monotone_queue[tail] = pro;
					f[k*v+j] = monotone_queue[head] + k * w;
					while(s < S[tail] - S[head] + 1) 
						head++;
				}
			}
			
		}
		System.out.println(f[V]);
	}
}
```

**2.背包正反选**

[HDU5616]: http://acm.hdu.edu.cn/showproblem.php?pid=5616

砝码：1 4 7

所称物重：2

> 首先正选，递推式中为*减号*，逆序遍历，每次只能选一个。

```java
for(int i=0;i<n;i++) {        
    for(int j=sum;j>=a[i];j--) {
        dp[j]|=dp[j-a[i]];          
    }
}
```

> 逆序遍历：

$$
sum = 12,dp[0]=1
$$

$$
i = 0,dp[12]=0,...,dp[1]=dp[1]|dp[0]=1
$$

$$
i=1,dp[12]=0,...,dp[5]=dp[5]|dp[1]=1,dp[4]=dp[4]|dp[0]=1
$$

$$
i=3,dp[12]=dp[12]|dp[5]=1,dp[11]=dp[11]|dp[4]=1,dp[8]=dp[8]|dp[1]=1,dp[7]=dp[7]|dp[7-7]=dp[7]|dp[0]=1
$$

> 假如正序遍历，代码修改为如下

```java
for(int i=0;i<n;i++) {
    for(int j=0;j+a[i]<=sum;j++) {
        dp[j]|=dp[j+a[i]];
    }
}
```

$$
sum=12,dp[0]=1
$$

$$
i=0,dp[0]=dp[0]|dp[1]=1,dp[1]=dp[1]|dp[2]=1,dp[2]=dp[2]|dp[3]=1
$$

*递推式中dp[2]中的2是由1+1凑出，1这个砝码用了两次，显然错误*

> 反选，正序，递推式中为*加号*，每次只能选一个

```java
for(int i=0;i<n;i++) {
    for(int j=0;j+a[i]<=sum;j++) {
        dp[j]|=dp[j+a[i]];
    }
}
```

> 正序遍历

$$
sum=12,dp[0]=dp[1]=dp[4]=dp[5]=dp[7]=dp[8]=dp[11]=dp[12]=1
$$

$$
i=0,dp[0]=1,dp[1]=1,dp[2]=0,dp[3]=dp[3]|dp[4]=1,dp[4]=1,dp[6]=dp[6]|dp[5]=1,...
$$

> 假如反序遍历，代码修改为如下

```java
for(int i=0;i<n;i++) {        
    for(int j=sum;j>=a[i];j--) {
        dp[j]|=dp[j-a[i]];          
    }
}
```

$$
sum=12,dp[0]=dp[1]=dp[4]=dp[5]=dp[7]=dp[8]=dp[11]=dp[12]=1
$$

$$
i=0,dp[12]=1,dp[11]=1,dp[9]=dp[9]|dp[8]=1
$$

*递推式中dp[9]中的9是由8+1凑出，相当于7+1+1，1这个砝码在天平同一端用了两次，显然错误*

总结：假设天平左边放置所称物体。第一轮正选背包，相当于计算出所有砝码所能组成的重量集合。第二轮背包，假设第二轮背包中选用了第一轮背包中所用的砝码，则相当于该砝码不被使用；假设第二轮背包中选用了第一轮背包中没有使用的砝码，相当于该砝码仅放置在天平左边。

**3.最大子段和**

> 动态规划算法

b[j]表示前j个元素的最大子段和，当b[j-1]>0时，b[j]=b[j-1]+a[j]，否则b[j]=a[j]。
$$
b[j]=max\{b[j-1]+a[j], a[j]\}
$$

> Code

```java
package PAT;

import java.util.*;
import java.io.*;

public class P1007DPOn {
	static int MAX = 100024;
	static int N;
	static int[] a = new int[MAX];
	static int MaxSubSum() {
		int bj = 0;
		int bj_1 = 0;
		for(int i=0; i<N; i++) {
			if(bj_1>0) 
				bj_1 += a[i];
			else 
				bj_1 = a[i];
			if(bj_1 > bj) 
				bj = bj_1;
		}
		return bj;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		N = sc.nextInt();
		for(int i=0; i<N; i++) {
			a[i] = sc.nextInt();
		}
		int sum = MaxSubSum();
		System.out.print(sum);
	}
}
```

**3.最长回文子串(longestPalindrome)**

> 输入：babad

b->a->b->a->d

0->1->2->3->4

> 维护一个半矩阵(TimeExceedLimit)

$$
table[i][j]
$$

表示输入字符串下标i->j（包含j)范围内的回文串集合（ArrayList维护）

按斜对角，自下而上，自左而右更新矩阵

|  4   | bab,aba,b,a,d | aba,b,a,d | b,a,d | a,d  | d    |
| :--: | ------------- | --------- | ----- | ---- | ---- |
|  3   | bab,aba       | aba       | b,a   | a    |      |
|  2   | bab           | a,b       | b     |      |      |
|  1   | b,a           | a         |       |      |      |
|  0   | b             |           |       |      |      |
|      | 0             | 1         | 2     | 3    | 4    |

所以babad的最长回文串为table\[0\]\[4\]中最长的元素

```java
package 动态规划;
import java.util.*;
import java.io.*;
public class LongestPalindrome {
	static final int MAX = 50;
	static ArrayList<String>[][] table = new ArrayList[MAX][MAX];
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		String in = sc.next();
		int n = in.length();
		sc.close();	
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				table[i][j] = new ArrayList<String>();
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j+i<n; j++) {
				if(in.charAt(j) == in.charAt(j+i)) {
					if(i == 0) {
						table[j][j+i].add(String.valueOf(in.charAt(j)));
					} else if(i == 1) {
						table[j][j+i].add(String.valueOf(in.subSequence(j, j+i+1)));
					} else if(table[j+1][j+i-1].size() == 1){
						table[j][j+i].add(in.substring(j, j+i+1));
					} else {
						table[j][j+i].addAll(table[j+1][j+i]);
						for(int k=0; k<table[j+1][j+i].size(); k++) {
							for(int l=0; l<table[j][j+i-1].size(); l++) {
								if(!table[j][j+i].get(k).equals(table[j][j+i-1].get(l))) {
									table[j][j+i].add(table[j][j+i-1].get(l));
								}
							}
							
						}
					}
				} else {
					table[j][j+i].addAll(table[j+1][j+i]);
					
					for(int k=0; k<table[j][j+i-1].size(); k++) {
						if(!table[j][j+i].contains(table[j][j+i-1].get(k))) {
							table[j][j+i].add(table[j][j+i-1].get(k));
						}
					}
				}
			}
		}
		int length = 0;
		String longestPalindrome = "";
		for(int i=0; i<table[0][n-1].size(); i++) {
			String str = table[0][n-1].get(i);
			if(table[0][n-1].get(i).length() > length) {
				length = table[0][n-1].get(i).length();
				longestPalindrome = table[0][n-1].get(i);
			}
		}
		System.out.print(longestPalindrome);//可能有多个结果，仅选择了第一个
	}
}
```

> 从右至左（保存较前的最长回文子串），从下而上更新矩阵，但是此时矩阵中存放的不是该子串的回文子串集合而是该子串是否为回文串，同时不断更新besti、bestj两个标识最长回文子串的左角标和右角标的变量。
>

b->a->b->a->d

0->1->2->3->4

> 初始化字符串长度为1和2的子串

| 4    |      |      |      |      | T    |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 3    |      |      |      | T    |      |
| 2    |      |      | T    |      |      |
| 1    |      | T    |      |      |      |
| 0    | T    |      |      |      |      |
|      | 0    | 1    | 2    | 3    | 4    |

| 4    |      |      |      | F    | T    |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 3    |      |      | F    | T    |      |
| 2    |      | F    | T    |      |      |
| 1    | F    | T    |      |      |      |
| 0    | T    |      |      |      |      |
|      | 0    | 1    | 2    | 3    | 4    |

[^T]: True，是回文子串
[^F]: False，非回文子串

> 状态转换方程

$$
dp[i][j]=dp[i+1][j−1],S[i]==S[j]
$$

$$
dp[i][j]=flase,S[i]!=S[j]
$$

```java
package 动态规划;

import java.util.*;
import java.io.*;
public class LongestPalindrome {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		String s = sc.next();
		sc.close();
		int len = s.length();
		if(len == 0)
			System.out.print("");
		boolean[][] DP = new boolean[len][len];
		for(int i=0; i<len; i++) {
			DP[i][i] = true;
		}
		int besti = 0;
		int bestj = 0;
		/*
		 * 倒序是为了维护较前的最长回文串
		 */
		for(int i=len-2; i>=0; i--) {
			if(s.charAt(i) == s.charAt(i+1)) {
				DP[i][i+1] = true;
				besti = i;
				bestj = i+1;
			}
				
		}
		
		for(int i=2; i<len; i++) {
			for(int j=len-1; j-i>=0; j--) {
				if(s.charAt(j-i) == s.charAt(j)) {
					DP[j-i][j] = DP[j-i+1][j-1];
					if(DP[j-i][j]) {
						besti = j-i;
						bestj = j;
					}
					
				}
					
			}
		}
		System.out.print(s.substring(besti, bestj+1));
	}
}
```



#### 二、贪心算法

#### 三、递归

**1.求行列式的值**

```java
import java.util.*;
import java.io.*;
public class MatrixA {
	public static final int MAX = 24;
	public static int[][] M = new int[MAX][MAX];
	public static int rec(int N, int[][] M) {
		if(N == 1)
			return M[1][1];
		int res = 0;
		for(int i=1; i<=N; i++) {
			int a = M[1][i];
			int[][] tempA = new int[MAX-1][MAX-1];
			for(int j=2; j<=N; j++) {
				int index = 1;
				for(int k=1; k<=N; k++) {
					if(k == i) 
						continue ;
					tempA[j-1][index++] = M[j][k];
				}
			}
			if(i%2 == 0) {
				res -= a*rec(N-1, tempA);
			} else {
				res += a*rec(N-1, tempA);
			}
			
		}
		return res;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int n = sc.nextInt();
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				M[i][j] = sc.nextInt();
			}
		}
		System.out.println("The result is：" + rec(n, M));
	}
}
```

#### 四、图

**1.DFS**

```C++
#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1010;
int n; //顶点数 
vector<int> Adj[MAXV];
bool vis[MAXV] = {false};
void DFS(int u, int depth) {
	vis[u] = true;
	for(int i=0; i<Adj[u].size(); i++) {
		int v = Adj[u][i];
		if(vis[v] == false) {
			DFS(v, depth+1);
		}
	} 
}

void DFSTravel() {
	for(int u=0; u<n; u++) {
		if(vis[u] == false) {
			DFS(u, 1);
		}
	}
} 
```

**2.BFS**

```C++
#include<bits/stdc++.h>
using namespace std;

vector<int> Adj[MAXV]; //图G， Adj[u]存放从顶点u出发可以到达的所有顶点
int n; //n为顶点数，MAXV为最大顶点数
bool inq[MAXV] = {false}; //若顶点i曾入过队列，则inq[i]==true。初值为false

void BFS(int u) { //遍历单个连通块 
	queue<int> q; //定义队列q
	q.push(u); //将初始点u入队
	inq[u] = true; //设置u已被加入过队列
	while(!q.empty()) { //只要队列非空 
		int u = q.front(); //取出队首元素
		printf("%d ", u); //访问u 
		q.pop(); //将队首元素出队 
		for(int i=0; i<Adj[u].size(); i++) { //枚举u出发能到达的所有顶点 
			int v = Adj[u][i];
			if(inq[v] == false) { //如果v未曾加入过队列 
				q.push(v); //将v入队
				inq[v] = true; //标记v以被加入过队列 
			}
		}
		 
	}	
} 

void BFSTravel() { //遍历图G 
	for(int u=0; u<n; u++) { //枚举所有顶点 
		if(inq[u] == false) { //如果u未曾加入过队列 
			BFS(u); //遍历u所在的连通块 
		} 
	} 
} 
```

**3.并查集**

```C++
#include<bits/stdc++.h>

const int N = 110;
int father[N]; //存放父亲节点 
bool isRoot[N]; //记录每个节点是否作为每个集合的根节点 

int findFather(int x) {
	int a = x;
	while(x !=father[x]) {
		x = father[x];
	}
	
	//路径压缩
	while(a != father[a]) {
		father[a] = x;
		a = father[a];
	} 
	
	return x;
}

void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	
	if(faA != faB) {
		father[faA] = faB;
	}
}

void init(int n) {
	for(int i=1; i<=n; i++) {
		father[i] = i;
		isRoot[i] = false;
	}
}
```

**4.Dijkstra最短路径**

```C++
#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1000;
const int INF = 1000000000;
struct Node {
	int v; //v为边的目标顶点
	int dis; //dis为边权 
}; 
vector<Node> Adj[MAXV]; //图G，Adj[u]存放从顶点u出发可以到达的所有顶点
int n; //n为顶点数，图G使用邻接表实现，MAXV为最大顶点数
int d[MAXV]; //起点到达各点的最短路径 
bool vis[MAXV] = {false}; //标记数组，vis[i] == true表示已访问。初值均为false

void Dijkstra(int s) { //s为起点 
	fill(d, d+MAXV, INF); //fill函数将整个d数组赋值为INF（慎用memset）
	for(int i=0; i<n; i++) { //循环n次
		int u = -1, MIN = INF; //u使d[u]最小，MIN存放该最小的d[u]
		for(int j=0; j<n; j++) { //找到未访问的顶点中d[]最小的
			if(vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		} 
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
		if(u == -1)
			return;
			
		vis[u] = true;
		//只有下面这个for循环与邻接矩阵的写法不同
		for(int j=0; j<Adj[u].size(); j++) {
			int v = Adj[u][j].v; //通过邻接表直接获得u能到达的顶点v
			if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]) {
				//如果v未访问&&以u为中介点可以使d[v]更优
				d[v] = d[u] + Adj[u][j].dis; //优化d[v] 
			} 
		} 
	}
} 
```

![D](https://github.com/TDYe123/Algorithm/blob/master/imgs/220px-Dijkstra_Animation.gif?raw=true)

> 附录

```java
JAVA:(PC)
Integer.MAX_VALUE = 2147483647
Long.MAX_VALUE = 9223372036854775807   
```

```c++
C++:(PC)
int.MAX_VALUE:2.147483647E9 
long long.MAX_VALUE: 9.223372036854776E18
```

```C++
//无穷大
const INF = 0x3f3f3f3f;
int arr[];
memset(arr, 0x3f, sizeof(arr));
//无穷小
const INF = 0xc0c0c0c0;
int arr[];
memset(arr, 0xc0, sizeof(arr));
```

