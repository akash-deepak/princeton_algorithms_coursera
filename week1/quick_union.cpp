# include <iostream>
using namespace std;
class QuickUnionUF
{
    private:
        int* id;
        int num_of_objects;
        int root(int p){
            while(p != id[p]) p = id[p];
            return p;
        }
    public:
        QuickUnionUF(int N){
            num_of_objects = N;
            id = new int[num_of_objects];
            for(int i = 0; i < num_of_objects; i++) id[i] = i;
        }
        bool connected(int p, int q){
            return (root(p) == root(q));
        }
        /*void print(){
            for(int i = 0; i < num_of_objects; i++) cout<<id[i]<<" ";
            cout<<endl;
        }*/
        void union_(int p, int q){
            int pid = root(p);
            int qid = root(q);
            id[pid] = qid;
        }
};
int main()
{
    int number_of_objects;
    bool check;
    int p,q;
    cin>>number_of_objects;
    QuickUnionUF QUF(number_of_objects);
    //QUF.print();
    while(cin>>p>>q){
        if(p == q) break;
        if(QUF.connected(p,q) == 1){
            cout<<"Already connected"<<endl;
            continue;
        }
        QUF.union_(p,q);
        //QUF.print();
    }
    while(cin>>p>>q){
        if(p == q) break;
        check = QUF.connected(p,q);
        cout<<check<<endl;
    }
    return 0;
}
