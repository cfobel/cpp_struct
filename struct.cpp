#include <iostream>
#include <vector>
#include <string>
#include <boost/format.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string/join.hpp>

using namespace std;

#define _ boost::format

struct test {
    const int &a;
    const int &b;
    test(const int &a, const int &b) : a(a), b(b) {}
};

template <class T>
struct test_vector {
    const vector<T> &av;
    test_vector<T>(const vector<T> &av) : av(av) {}
};

int main() {
    int i = 0;
    int k = 5;

    test t = test(i, k);

    cout << _("original:   %d, %d") % i % k << endl;
    cout << _("struct ref: %d, %d") % t.a % t.b << endl;

    i = 10;
    k = 15;

    cout << _("original:   %d, %d") % i % k << endl;
    cout << _("struct ref: %d, %d") % t.a % t.b << endl;

    int element_count = 10;
    vector<int> v(element_count);

    int count = 0;
    BOOST_FOREACH(int &i, v) {
        i = count++;
    }

    test_vector<int> tv(v);

    vector<string> msg;

    BOOST_FOREACH(int i, v) {
        msg.push_back((_("%d") % i).str());
    }
    cout << _("original:     [%s]") % boost::algorithm::join(msg, ", ") << endl;

    msg.clear();
    BOOST_FOREACH(int i, tv.av) {
        msg.push_back((_("%d") % i).str());
    }
    cout << _("struct ref:   [%s]") % boost::algorithm::join(msg, ", ") << endl;

    return 0;
}
