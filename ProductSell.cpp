/*

Product Selling App Implementation
that allows several options such as:
1 Add a Product
2 View the Products
3 Sell a Product
4 View Profit
5 Exit

We keep details about listed products in a structure: name, quantity, sell price, buy price
and use a switch case structure to choose one of the given options of the app.

1 - For product listing: if product number is bigger then 100 return error message as long 
if there are 100 products stored, else enter all details about the product, such as quantity, 
net price, sell price.

2 - For products view or check: In order to view products that you stored, if products number 
is 0 then you have no products stored yet, then for each product display name, quantity, net/sell price.

3 - For products sell: Enter the product's name to be sold, go through the list of products and
if given product is found by name, enter quantity to be sold, generate remaining quantity after
selling a product and calculate profit as difference between net price and sell price.

4 - For check profit by sell products: multiplicate profit with the quantity to get total 
profit after a sell.

5 - Exit: command to exit app.

*/


# include <iostream>
# include <cstdlib>
# include <fstream>
using namespace std;


int press;
int n=0;


// function to choose one of the given options
int manage()
{
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" Press one of the following options"<<endl;
    cout<<" Press 1 to Add a Product"<<endl;
    cout<<" Press 2 to View the Products"<<endl;
    cout<<" Press 3 to Sell a Product"<<endl;
    cout<<" Press 4 to View Profit"<<endl;
    cout<<" Press 5 to Exit"<<endl;
    cout<<"-------------------------------------------------"<<endl;

    cout<<" Enter : ";
    cin>>press;

    return press;
}

// structure to keep details about listed products
struct products_listed
{
    std::string name;
    int quantity;
    float sell_price;
    float buy_price;
};

int main()
{
    // array to keep listed products
    products_listed arr[100];

    float profit = 0;

    cout<<endl;
    cout<<"Welcome To Your Products Shop"<<endl;

    // call manage function to choose one of the given options
    begin:
    manage();

    // switch case instruction to go through the options
    switch (press)
    {
        ///** For Product listing **///
        case 1:

            cout<<"====== :: Product Listing On Your Shop :: ======"<<endl<<endl;

            for(int i = (1+n) ; i <= 100 ; i++)
            {
		// if product number is bigger then 100 return error message as long if there are 100 products stored
                if(i>100)
                {
                    cout<<"Can't listing and You exceed the number of your products"<<endl;
                }
                else
                {	
		     // read product name
                     cout<<"Enter the Name of the Product no. "<<i<<endl;
                     cin>>arr[i].name;
		     
		     // if you enter 2 products with the same name - error message
                     if(arr[i].name==arr[i-1].name)
                     {
                         cout<<"The Products can't have the same name"<<endl<<endl;
                     }
                     else
                     {
			 // enter all details about the product, such as quantity, net price, sell price
                         cout<<"Enter the Quantity of "<<arr[i].name<<endl;
                         cin>>arr[i].quantity;
                         cout<< "Enter the Net Price of " << arr[i].name <<endl;
                         cin>>arr[i].buy_price;
                         cout<<"Enter the Sell Price of "<<arr[i].name<<endl;
                         cin>>arr[i].sell_price;

                         cout<<endl;

			 // successfully added product message
                         cout<<" *** Your Product is successfully added"<<endl<<endl;

			 // increase product nr to go further through the list
                         n++;
                         goto begin;
                     }
                  }
                }
                break;

        ///** ============ For Products View Or Check **///
        case 2:

            cout<<"====== :: View Products That You Stored :: ======"<<endl<<endl;

	    // if products number is 0 then you have no products stored yet
            if(n==0)
            {
                cout<<"*** You have no products yet"<<endl<<endl;
                goto begin;
            }
            else
            {
		// for each product display name, quantity, net/sell price
                for(int i =1 ; i <=n ; i++)
                {
                    cout<<"Product no. "<<i<<" Name is : "<<arr[i].name<<endl;
                    cout<<"Product no. "<<i<<" Quantity is: "<<arr[i].quantity<<" Pics."<<endl;
                    cout<<"Product no. "<<i<<" Net price is: "<<arr[i].buy_price<<" tk."<<endl;
                    cout<<"Product no. "<<i<<" Sell price is: "<<arr[i].sell_price<<" tk."<<endl;
                    cout<<endl<<endl;
                }
                goto begin;
             }
             break;

        ///** ============ For Products Sell **///
        case 3:

             char x[100];
             int y;

             cout<<"====== :: Product Selling On Your Shop :: ======"<<endl<<endl;
             cout<<"Enter the Product's Name to be sold"<<endl;
             cin>>x;

 	     // go through the list of products
             for(int i=1; i<=n; i++)
             {  
		// if given product is found by name
                if (x==arr[i].name)
                {
		    // enter quantity to be sold
                    cout<<"Enter the Quantity to be sold"<<endl;
                    cin>>y;

		    // is quantity to be sold is bigger then available quantity, error message
                    if (y>arr[i].quantity)
                    {
                       cout<<"The products number shouldn't be less than the sold ones"<<endl<<endl;
                    }
                    else
                    {
			// generate remaining quantity after selling a product 
                        cout<<endl;
                        cout<<" *** The Remaining Quantity is "<<arr[i].quantity-y<<" Pics."<<endl<<endl;

                        arr[i].quantity=arr[i].quantity-y;

                        cout<<" *** Total Selling price is "<<arr[i].sell_price*y<<" tk."<<endl<<endl;

                        ///* File create system *///
                        ofstream myfile("Shopping_and_Bills.txt");

                           if (myfile.is_open())
                           {
                                myfile <<"\n";
                                myfile <<"     Your Bills:              \n";
                                myfile <<"___________________________________________\n";
                                myfile <<" Product Name : "<<x<<"\n";
                                myfile <<" Total Quantity : "<<y<<" Pics. \n";
                                myfile <<" Total Selling Price is : "<<arr[i].sell_price*y<<" tk. \n";

                                myfile.close();
                            }
                            else
                                cout << "Unable to open file";
                        /// closing file system

                    }
		    
                    // calculate profit as difference between net price and sell price
                    profit += arr[i].sell_price - arr[i].buy_price;


                  }
                  else
		       // if wrong product name entered, error message
                       cout<<"The Product is not found"<<endl<<endl;
                  }
                  goto begin;
                  break;

        ///** ============ For Check Profit by sell products **///
        case 4:
	    
	    // multiplicate profit with the quantity to get total profit after a sell
            cout<<"====== :: Your Profit :: ======"<<endl<<endl;
            cout<<" *** Profit: "<<profit*y<<" tk."<<endl<<endl;

            goto begin;
            break;

        ///** ============ Close The Program **///
        case 5:

            cout<<"Terminate the Program"<<endl<<endl;
	    
 	    // command to exit app
            exit(0);
     }

     return 0;

}