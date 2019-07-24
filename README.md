# Algorithm

Algorithm 算法设计与分析

#### 一、动态规划

##### 1.单调队列优化多重背包

> 原始状态转换方程：

$$
c[i]  =  min(s[i], \quad j/v[i])
$$

$$
f[i][j] = max(f[i-1][j-k*v[i]]+k*w[i]) ，0<=k<=c[i]
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
f[i][j] = max(f[i-1][k'*v[i]+b]-k'w[i]+a*w[i])， a-c[i] <= k <= a
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



#### 二、贪心算法

#### 三、递归

**1.求行列式的值****

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

