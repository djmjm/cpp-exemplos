#include <iostream>
#include <time.h>

#define RANDOMIZE srand(time(NULL))
#define COUT_CUSTOM_OPERATOR_LIST \
        ostream& operator << ( ostream &out, List &list ){ \
        auto listContent = list.getList(); auto listLabel = list.getLabel(); \
        out << listLabel << listContent << endl;return out;} \

#define COUT_CUSTOM_OPERATOR_INT \
        ostream& operator << ( ostream &out, int *list ){ int size = list[0]; \
        for(int i = 1; i <= size; i++){ out << " |" << list[i] << "| ";} out << endl; \
        return out;}

using namespace std;

enum sort { descendent, ascendent, unsorted};

class List{
    private:
        int *list;
        int size;
        sort type;

        void bubble_sort_desc(){
            for(int i = 1; i <= size; i++){
                for(int j = 1; j <= size; j++){
                    if(list[i] > list[j]){
                        int temp = list[i];
                        list[i] = list[j];
                        list[j] = temp;
                    }
                }
            }
        }

        void bubble_sort_asc(){
            for(int i = 1; i <= size; i++){
                for(int j = 1; j <= size; j++){
                    if(list[i] < list[j]){
                        int temp = list[i];
                        list[i] = list[j];
                        list[j] = temp;
                    }
                }
            }
        }

        void generate_list_number(){
            list[0] = size;
            for(int i = 1; i <= size; i++){
                list[i] = rand() % 1024;
            }

            if(type == descendent) { bubble_sort_desc(); }
            if(type == ascendent) { bubble_sort_asc(); }
        }

        void create_object(){
            size = 10;
            list = new int(size+1);
            generate_list_number();
        }

    public:
        List(){
            type = unsorted;
            create_object();
        };
        List(sort type){
            this->type = type;
            create_object();
        }

        int *getList(){
            return list;
        }

        string getLabel(){
            if(type == ascendent) return " | ASCENDENT LIST >>> \n";
            if(type == descendent) return " | DESCENDENT LIST >>> \n";
            return " | UNSORTED LIST >>> \n";
        }

        friend ostream& operator << ( ostream &out, const List &list);
};

COUT_CUSTOM_OPERATOR_INT;
COUT_CUSTOM_OPERATOR_LIST;

int main(){

    RANDOMIZE;

    auto unsortedList = *(new List());
    auto descendentList = *(new List(descendent));
    auto ascendentList = *(new List(ascendent));

    cout << unsortedList
         << descendentList
         << ascendentList
         ;

    return 0;
}

