#include <iostream>
#include <vector>

using namespace std;

void PrintArray(vector<int> &arr){

    for(auto n : arr)
		cout << n << " ";
	cout << endl;
}


void simpleApproach(vector <int> &num) // O(N^3) as three loops are superimposed.
{
    int N = (int)num.size();
    int max_sum=INT_MIN;
    int idx1=0, idx2=0;
    
    for(int l=1; l<=N ; ++l){
        printf("%d: ",l);
        for(int i=0; i<N-l+1 ; ++i){
            printf("(");
            int subSum=0;
            for(int j=i; j<i+l ; ++j){
                subSum += num[j];
                printf("%3d", num[j]);
            }

            if(subSum > max_sum) {
                max_sum = subSum;
                idx1 = i;
                idx2 = i+l-1;
            }
            printf(") %d,",subSum);
        }
        printf("\n");
    }
    
    cout << max_sum << " " << idx1 << " " << idx2 << endl;
}


void n2_complexity(vector<int> &num){
    int N = (int)num.size();
    int max_sum=INT_MIN;
    int idx1=0, idx2=0;

    for(int i=0; i<N; ++i){
        int subSum = 0;
        for(int j=i; j<N ;++j){
            subSum += num[j];
            
            if(subSum > max_sum){
                max_sum = subSum;
                idx1=i;
                idx2=j;
            }
        }
    }
    cout << max_sum << " " << idx1 << " " << idx2 << endl;
}



void n1_complexity(vector<int> &num){
    int N=(int)num.size();
    int max_sum = INT_MIN;
    int idx1=-1, idx2=-1;
    int s = 0;
    
    int currSum=0;
    for(int i=0; i<N ; ++i){
        
        currSum += num[i];
        if(currSum < 0) {
            currSum = 0;
            s = i+1;
        }
        
        if(currSum > max_sum){
            max_sum = currSum;
            idx1 = s;
            idx2 = i;
        }
    }
    
    cout << max_sum << " " << idx1 << " " << idx2 << endl;
    
    vector<int> subSeq(num.begin()+idx1, num.begin()+idx2+1);
    
    cout << subSeq.size() << endl;
    for(auto n: subSeq)
        cout << n <<" ";
    cout << endl;
}

int main(){
    vector<int> num={-2,-3,4,-1,-2,1,5,-3};
    PrintArray(num);

    //simpleApproach(num);  // O(n^3)
    //n2_complexity(num);   // O(n^2)
    n1_complexity(num);  // O(n) complexity
    
    
    
	return 0;
}
