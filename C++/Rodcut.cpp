//============================================================================
// Name        : Rodcut.cpp
// Author      : SidPro
// Version     : 1.0
// Description : Rod cutting problem
//============================================================================

#include <iostream>
#include <cmath>
#include <tuple>
using namespace std;
#define Min -1000
/*We typically apply dynamic programming to optimization problems. Such problems
 *can have many possible solutions. Each solution has a value, and we wish to
 *find a solution with the optimal (minimum or maximum) value. We call such a
 *solution an optimal solution to the problem, as opposed to the optimal solution,
 *since there may be several solutions that achieve the optimal value.
 *When developing a dynamic-programming algorithm, we follow a sequence of
 *four steps:
 *1. Characterize the structure of an optimal solution.
 *2. Recursively define the value of an optimal solution.
 *3. Compute the value of an optimal solution, typically in a bottom-up fashion.
 *4. Construct an optimal solution from computed information.
 *Steps 1–3 form the basis of a dynamic-programming solution to a problem. If we
 *need only the value of an optimal solution, and not the solution itself, then we
 *can omit step 4. When we do perform step 4, we sometimes maintain additional
 *information during step 3 so that we can easily construct an optimal solution.
 */
/*	The rod-cutting problem is the following. Given a rod of length N inches and a
	table of prices pi for i =1,2,...n, determine the maximum revenue Rn obtainable
	by cutting up the rod and selling the pieces. Note that if the price Pn for a rod
	of length N is large enough, an optimal solution may require no cutting at all.
	Possible ways to cut rod is 2^n-1
	 */

//Recursive top-down implementation
// Time complexity 2^n
int CUT_ROD(int p[],int n){
	if(n==0)return 0;
	int q = Min;
	for(int i=0;i<n;++i){
		q = max(q,p[i] + CUT_ROD(p,n - i - 1));
	}
	return q;
}
//top-down with memoization

/* In this approach, we write
the procedure recursively in a natural manner, but modified to save the result of
each subproblem (usually in an array or hash table). The procedure now first checks
to see whether it has previously solved this subproblem. If so, it returns the saved
value, saving further computation at this level; if not, the procedure computes the
value in the usual manner. We say that the recursive procedure has been memoized;
it “remembers” what results it has computed previously.
The running time of its top-down counterpart,
MEMOIZED-CUT-ROD, is also n^2 although this running time may be a little
harder to see. Because a recursive call to solve a previously solved subproblem
returns immediately, MEMOIZED-CUT-ROD solves each subproblem just once. It
solves subproblems for sizes 0,1,...n. To solve a subproblem of size n,the for
loop iterates n times. Thus, the total number of iterations of this for
loop, over all recursive calls of MEMOIZED-CUT-ROD, forms an arithmetic series,
giving a total of n^2 iterations, just like the inner for loop of BOTTOM-UPCUT-
ROD.
 * */
int Memoization_CUT_ROD_AUX(int p[],int r[],int n){
	int q = Min;
	if(r[n - 1]>=0)return r[n - 1];
	if(n==0) q=0;
	else{
		for(int i=0;i<n;++i)
			q = max(q,p[i]+Memoization_CUT_ROD_AUX(p,r,n - i - 1));
	}
	r[n - 1] = q;
	return q;
}

int Memoization_CUT_ROD(int p[],int n){
	int r[n];
	for(int i=0;i<n;++i)r[i]=Min;
	return Memoization_CUT_ROD_AUX(p,r,n);
}

//bottom-up dynamic-programming

tuple<int,int *> Bottom_UP_CUT_ROD(int p[],int n){
	int r[n + 1];
	int *s = new int[n + 1];
	r[0] = 0;
	s[0] = 0;
	for(int i=0;i<n;++i){
		int q = Min;
		for(int j=0;j<=i;++j){
			if(q < p[j] + r[i - j]){
				q = p[j] + r[i - j];
				s[i + 1] = j+1;
			}
		}
	r[i + 1]=q;
	}
	return make_tuple(r[n],s);
}

/* 	The bottom-up and top-down versions have the same asymptotic running time.
	The running time of procedure BOTTOM-UP-CUT-ROD is n^2, due to its
	doubly-nested loop structure.
 * */

int main() {
	int p[] = {1,5,8,9,13,17,18,22,25,30};
	int size = sizeof(p)/sizeof(p[0]);
	cout<<"Recursive top-down: ";
	int ans = CUT_ROD(p,size);
	int *s;
	cout<<" Max Price:"<<ans<<"\n";
	cout<<"Memoization top-down: ";
	ans = Memoization_CUT_ROD(p,size);
	cout<<" Max Price:"<<ans<<"\n";
	tie(ans,s)=Bottom_UP_CUT_ROD(p,size);
	cout<<"Dynamic programming bottom-up: "<<ans<<"\n";
	cout<<"length of cuts: ";
	while(size>0){
		cout<<s[size]<<" ";
		size = size - s[size];
	}
	return 0;
}
