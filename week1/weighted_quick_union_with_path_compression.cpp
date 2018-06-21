# include <iostream>
using namespace std;
class WQUPC
{
    private:
        int no_of_objects;
        int* id;
        int* size_;
        int root(int p){
            //path compression
            while(p != id[p]){
                id[p] = id[id[p]];
                p = id[p];
            }
        }
    public:
        WQUPC(int N){
            no_of_objects = N;
            id = new int[no_of_objects];
            size_ = new int[no_of_objects];
            for(int i = 0; i < no_of_objects; i++){
                id[i] = i;
                size_[i] = 1;
            }
        }
       bool connected(int p,int q){
           return (root(p) == root(q));
       }
       void union_(int p, int q){
           int pid = root(p);
           int qid = root(q);
           if(size_[pid] < size_[qid]){
                id[pid] = qid;
                size_[qid] = size_[qid] + size_[pid];
           }
           else{
                id[qid] = pid;
                size_[pid] = size_[pid] + size_[qid];
           }
       }
       void print(){
           for(int i = 0; i < no_of_objects; i++) cout<<id[i]<<" ";
           cout<<endl;
           for(int i = 0; i < no_of_objects; i++) cout<<size_[i]<<" ";
           cout<<endl;
       }
};
int main()
{
    int number_of_objects,p,q;
    bool check;
    cin>>number_of_objects;
    WQUPC obj(number_of_objects);
    obj.print();
    while(cin>>p>>q){
        if(p == q) break;
        if(obj.connected(p,q) == 1){
            cout<<"Already connected"<<endl;
            continue;
        }
        obj.union_(p,q);
        obj.print();
    }
    while(cin>>p>>q){
        if(p == q) break;
        check = obj.connected(p,q);
        cout<<check<<endl;
    }
    return 0;
}
