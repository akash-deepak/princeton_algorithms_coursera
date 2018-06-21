# include <iostream>
using namespace std;
class QuickFindUF
{
    private:
        int* id;
        int no_of_objects;
    public:
        QuickFindUF(int N){
            no_of_objects = N;
            id = new int[no_of_objects];
            for(int i = 0; i < no_of_objects; i++) id[i] = i;
        }
        bool connected(int p, int q){
            return (id[p] == id[q]);
        }
        /*To check the working of the QuickFind Class.
        void print(){
            for(int i = 0; i < no_of_objects; i++) cout<<id[i]<<" ";
            cout<<endl;
        }*/
        void union_(int p, int q){
            int pid = id[p];
            int qid = id[q];
            for(int i = 0; i < no_of_objects; i++){
                if(id[i] == pid) id[i] = qid;
            }
        }
};
int main(){
    int number_of_objects;
    int p,q;
    bool check;
    cin>>number_of_objects;
    QuickFindUF UF(number_of_objects);
    //UF.print();
    while(cin>>p>>q){
        // To break out of the while loop
        if(p == q) break;
        if(UF.connected(p,q) == 1){
            cout<<"Already connected"<<endl;
            continue;
        }
        UF.union_(p,q);
        //UF.print();
    }
    while(cin>>p>>q){
        //to break out of the while loop
        if(p == q) break;
        check = UF.connected(p,q);
        cout<<check<<endl;
    }
    return 0;
}
