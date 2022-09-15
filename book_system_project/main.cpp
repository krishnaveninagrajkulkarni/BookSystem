//
//  main.cpp
//  book_system_project
//
//  Created by krishnaveni kulkarni on 14/09/22.
//  Copyright © 2022 krishnaveni kulkarni. All rights reserved.
//

//created a book system,
//1.which will accept no.of books to be inserted from the user.
//2.Then it creates an array of objects using dynamic memory allocation for specified no.of books(inserted by user)
//3.Insert records, Display single record, Delete single record, Display All, Delete ALL & Exit functions are created
//4. On Delete All & Exit, dynamic memory is released and pointer is assigned to NULL
//5. Validation on integer n character variables is not done
#include <iostream>
using namespace std;
class Book
{
    int book_id;
    float book_price;
    char book_title[15];
    char book_author[15];

public:
    static int total_books;                      //static/class Member variable declaration
    static int noofbooks_tobeinserted;          //static/class Member variable declaration
    static bool insertflag ;                    //static/class Member variable declaration
    
    //Default Constructor
    Book()
    {
        book_id = 0;
        book_price = 0.0;
    }
 
    static int choose_option(){
        int optn = 0;
        cout<<"\n\n";
        if (insertflag == false){
            cout<<"1.Insert Records"<<"\n";
        }
        cout<<"2.Display Record"<<"\n";
        cout<<"3.Delete Record"<<"\n";
        cout<<"4.Display All"<<"\n";
        cout<<"5.Delete All"<<"\n";
        cout<<"6.Exit"<<"\n";
        cout<<"Please select the option: ";
        cin>>optn;
        
        if ((optn == 1) && (insertflag == false))
        {
            cout<<"\n"<<"How many books data you want to insert?";
            cin>>noofbooks_tobeinserted;
        }
        return optn;
    }
    
    void display_alldetails()
    {
        if (book_id != 0){
            cout<<"Book id = "<<book_id<<"\n";
            cout<<"Book price = "<<book_price<<"\n";
            cout<<"Book title = "<<book_title<<"\n";
            cout<<"Book author = "<<book_author<<"\n";
        }
    }
    bool display_single_record(int book_tobe_displayed)
    {
        if (book_id == book_tobe_displayed){
            cout<<"Book id = "<<book_id<<"\n";
            cout<<"Book price = "<<book_price<<"\n";
            cout<<"Book title = "<<book_title<<"\n";
            cout<<"Book author = "<<book_author<<"\n";
            return true;
        }else{
            return false;
        }
    }
    void insert_newbooks()
    {
        cout<<"Enter Book id = ";
        cin>>book_id;
        cout<<"Enter Book price = ";
        cin>>book_price;
        cout<<"Enter Book title = ";
        cin>>book_title;
        cout<<"Enter Book author = ";
        cin>>book_author;

        total_books = total_books  + 1;
        
    }
    bool delete_single_book(int book_tobe_deleted){
        
        if (book_id == book_tobe_deleted){
            book_id = 0;
            book_price = 0;
            return true;
        }else{
            return false;
        }
    }

};

int Book:: total_books;             //class member function defination
int Book:: noofbooks_tobeinserted; //class member function defination
bool Book:: insertflag = false;             //class member function defination

int main(int argc, const char * argv[]) {
    int option = 0;
    bool deleteall_flag = false;
    bool result = false;
    int bookid = 0;
    
//Creating 3 objects using dynamic binding
do{
    option = Book:: choose_option();
    //if_1
    if(option == 1){
        Book *b1 = new Book[Book::noofbooks_tobeinserted];
        cout<<"\n"<<"Memory intialised for data storage"<<"\n";
 
        while(option != 6){
        
            switch(option){
                case 1: //Insert multiple records
                    if (Book:: insertflag  == false){
                        Book::insertflag = true;
                        for(int i=0;i<Book::noofbooks_tobeinserted;i++)
                        {
                            b1[i].insert_newbooks();
                    
                        }
                        cout<<"All Books details inserted successfully"<<"\n";
                        cout<<"Total Books Available = "<<Book::total_books<<"\n";
                    }else{
                        cout<<"Wrong option, please choose correct option"<<"\n";
                    }
                    break;
                case 2: //Display specified record
                    cout<<"\n"<<"Enter book id to be displayed : ";
                    cin>>bookid;
                    for(int i=0;i<Book::noofbooks_tobeinserted;i++)
                    {
                        result = b1[i].display_single_record(bookid);
                        if (result == true){
                            break;
                        }
                    }
                    if(result == false){
                        cout<<"Data not found - Bookid doesn't exist"<<"\n";
                    }
                    
                    break;
                case 3: //Delete specified record
                    if (deleteall_flag == false){
                        cout<<"Enter book id to be deleted : ";
                        cin>>bookid;
                        for(int i=0;i<Book::noofbooks_tobeinserted;i++)
                        {
                            result = b1[i].delete_single_book(bookid);
                            if (result == true){
                                cout<<"Record deleted means book id is intialised to zero, but memory still exists"<<"\n";
                                Book:: total_books = Book:: total_books -  1;
                                break;
                            }
                            
                        }
                        if(result == false){
                            cout<<"Data not found - Bookid doesn't exist"<<"\n";
                        }
                        cout<<"Total Books Available = "<<Book::total_books<<"\n";
                        
                    }else{
                        cout<<"All records deleted"<<"\n"; }
                break;
                case 4: //Display All the Records
                    if (Book::total_books == 0){
                        cout<<"There are no records to display"<<"\n";
                    }else {
                        for(int i=0;i<Book::noofbooks_tobeinserted;i++)
                        {
                            b1[i].display_alldetails();
                        }
                        cout<<"Total Books Available= "<<Book::total_books<<"\n";
                    }
                break;
                case 5: //Delete All the Records
                    if (Book::total_books == 0){
                        cout<<"There are no records"<<"\n";
                    } else {
                        deleteall_flag = true;
                        delete [] b1;
                        b1 = nullptr;
                        Book::total_books = 0;
                        cout<<"All Records deleted,there are no books available"<<"\n";
                        cout<<"Total Books = "<<Book::total_books<<"\n";
                        
                    }
                    break;
                case 6:
                    break;
                default:
                    cout<<"Wrong option, please choose correct option"<<"\n";
                    break;
        } //Switch ends
            if(option !=6 ){
                option = Book::choose_option();
            }else{
                break;
            }
    }//while loop ends

    delete []b1;
    b1 = nullptr;
}//if_1
    else{
        cout<<"Please select options again:"<<"\n";
        option = Book:: choose_option();
    }
} while (option != 6); //do-while end
    
    cout<<"Finallllll Endddddd"<<"\n";
    return 0;
}
