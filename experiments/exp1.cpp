    #include <iostream>
    using namespace std;

    class List {
    private:
        int *arr;
        int sizeofarray;
        int sizeoflist;

    public:
        // constructor
        List(int size) {
            arr = new int[size];
            sizeofarray = size;
            sizeoflist = 0;
        }

        // insertion at the beginning of list
        void insert_first(int element) {
            if (sizeoflist < sizeofarray) {
                for (int i = sizeoflist; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[0] = element;
                sizeoflist++;   
            } else {
                cout << "List is already full" << endl;
            }
        }

        // insertion at the end of list
        void insert_last(int element) {
            if (sizeoflist < sizeofarray) {
                arr[sizeoflist] = element;
                sizeoflist++;
            } else {
                cout << "List is full, unable to insert" << endl;
            }
        }

        // insertion at other index
        void insert_at(int index, int element) {
            if (sizeoflist == sizeofarray) {
                cout << "List already full" << endl;
                return;
            }
            if (index < 0 || index > sizeoflist) {
                cout << "Invalid index" << endl;
                return;
            }
            for (int i = sizeoflist; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
            sizeoflist++;
        }

        // deletion from the beginning
        int delete_first() {
            if (sizeoflist == 0) {
                cout << "List is empty" << endl;
                return -1;
            }
            int element = arr[0];
            for (int i = 1; i < sizeoflist; i++) {
                arr[i - 1] = arr[i];
            }
            sizeoflist--;
            return element;
        }

        // deletion from the end 
        int delete_last() {
            if (sizeoflist == 0) {
                cout << "List is empty" << endl;
                return -1;
            }
            int element = arr[sizeoflist - 1];
            sizeoflist--;
            return element;
        }

        // deleting from other positions 
        int delete_at(int index) {
            if (sizeoflist == 0) {
                cout << "List is empty" << endl;
                return -1;
            }
            if (index < 0 || index >= sizeoflist) {
                cout << "Invalid index" << endl;
                return -1;
            }
            int element = arr[index];
            for (int i = index; i < sizeoflist - 1; i++) {
                arr[i] = arr[i + 1];
            }
            sizeoflist--;
            return element;
        }

        // finding an element
        void find_elt(int key) {
            for (int i = 0; i < sizeoflist; i++) {
                if (arr[i] == key) {
                    cout << "Key is present at index = " << i << endl;
                    return;
                }
            }
            cout << "Key is not present in the list" << endl;
        }

        // displaying the list
        void display() {
            for (int i = 0; i < sizeoflist; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    };

    int main() {
        List myList(10);
        //inserting element at last position
        myList.insert_last(11);
        myList.insert_last(12);
        myList.insert_last(13);
        myList.insert_last(14);
        myList.insert_last(15);
        myList.display();

        //inserting at front of list
        myList.insert_first(10);
        myList.display();

        //deletion from front
        int element = myList.delete_first();
        cout<<"Element deleted : "<<element<<endl;
        myList.display();

        //deletion from last
        int ans = myList.delete_last();
        cout<<"Element deleted : "<<ans<<endl;
        myList.display();

        //insertion at random index
        myList.insert_at(1,100);
        myList.display();
        
        //deleting at random index
        int ans1 = myList.delete_at(2);
        cout<<"Element deleted : "<<ans1<<endl;
        myList.display();

        //finding an element

        //element does not exists
        myList.find_elt(40);
        //element exists
        myList.find_elt(11);

        return 0;
    }
