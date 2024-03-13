#include <iostream>
#include <vector>
#include<chrono>
using namespace std;
using namespace chrono;
const int ALPHA_SIZE=256;
void processpattern(const string &pattern,vector<int> & badcharshift){
    int m=pattern.length();
    for(int i=0;i<ALPHA_SIZE;i++){
        badcharshift[i]=m;

    }
    for(int i=0;i<m-1;i++){
        badcharshift[pattern[i]-'A']=m-1-i;
    }
}
void searchPattern(const string &text,const string & pattern){
    int m=pattern.length();
    int n=text.length();
    
    vector<int> badcharshift(ALPHA_SIZE);

    processpattern(pattern,badcharshift);

    int i=0;

    while(i<=n-m)
    {
        int j=m-1;
        while(j>=0&&pattern[j]==text[j+i]){
            j--;
        }
        if(j<0){
            cout<<"pattern found at"<<i;
            i+=badcharshift[text[i+m-1]-'A'];
        }
        else{
            i+=badcharshift[text[i+j]-'A'];
        }
    }
}
int main() {
    string text = "ACGTACGTTGACGTACGTACGT";
    string pattern = "ACGT";
    auto start_time =high_resolution_clock::now();
    cout << "DNA Sequence: " << text << endl;
    cout << "Pattern to search: " << pattern << endl;

    searchPattern(text, pattern);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;
    return 0;
}