#include <vector>
#include <list>
#include <iostream>

using namespace std;

template <typename Container>
void Write(Container& ds, ostream& os)
{
    typename Container::iterator iter = ds.begin();
    for (; iter != ds.end(); ++iter)
        os << *iter <<  " ";
    os << endl;
}

int main(int argc, char* argv[])
{
    list<float> mylist;
    vector<float> myvector;

    for (float i = 0; i < 10; i++)
    {
        mylist.push_back(i);
        myvector.push_back(i + 50);
    }

    Write(mylist, cout);

    Write(myvector, cout);

    /*
 
    
   
    auto vecIter = myvector.begin();
    for (; vecIter != myvector.end(); ++vecIter)
    {
        cout << *vecIter << " ";
    }
    */
}
