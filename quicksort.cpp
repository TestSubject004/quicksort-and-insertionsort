# include <iostream>
# include <vector>
# include <fstream>

using namespace std;

template <typename Comparable>
void insertionSort(vector <Comparable> &a){
    for (int p =1 ; p <a.size();++p){
        Comparable tmp = move(a[p]);
        int j;
        for (j = p;j>0 && tmp<a[j-1];--j)
            a[j] = move(a[j-1]);
        a[j] = move(tmp);
    }

}

template <typename Comparable>
const Comparable& median3(vector<Comparable>& a,int left, int right ){
    int center = (left + right)/2;
    if (a[center] < a[left])
        swap(a[left], a[center]);
    if( a[ right ] < a[ left ] )
        swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        swap( a[ center ], a[ right ] );

    swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}


template <typename Comparable>
void quicksort(vector<Comparable> &a, int left, int right){
    if (left + 10 <= right){
        const Comparable & pivot = median3(a, left, right);

        int i = left, j = right-1;

        for (;;){
            while (a[++i] < pivot) {}
            while (pivot < a[--j]) {}

            if (i<j)
                swap(a[i],a[j]);
            else
                break;
            
        }
        swap(a[i], a[right-1]);
        quicksort(a,left,i-1);
        quicksort(a,i+1, right);
    }
    else{
        cout<<"activate ins sort \n";
        insertionSort(a);
    }
        
}

template <typename Comparable>
void quicksort(vector<Comparable>&a){
    quicksort(a, 0 , a.size()-1);
}




int main(){
    cout<<"enter file name \n";
    string name;
    cin>>name;
    ifstream ist {name};

    vector<int> s;
    int test;
    for (int test; ist >> test;)
        s.push_back(test);

    
    quicksort(s);
    
    for (auto i : s)
        cout <<i<< endl;
    

    return 0;
    
}
