#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;          // order_of_key(a);find_by_order(n) // greater<int> for descending order
using ordered_set_g = __gnu_pbds::tree<int, __gnu_pbds::null_type, greater<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;     // order_of_key(a);find_by_order(n) // greater<int> for descending order
using ordered_set_le = __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n) // greater<int> for descending order

int main()
{
    cout << "Careful: order_of_key(a) effectively does order_of_key(a-0.5)\n";
    ordered_set s;
    s.insert(1);
    s.insert(3);
    s.insert(4);
    cout << "{1, 3, 4}\n";
    cout << "nums < 0: " << s.order_of_key(0) << "\n";
    cout << "nums < 2: " << s.order_of_key(2) << "\n";
    cout << "nums < 3: " << s.order_of_key(2) << "\n";
    cout << "nums < 10: " << s.order_of_key(10) << "\n";
    // find_by_order returns an iterator, so dereference it to get the value
    cout << "0th: " << *s.find_by_order(0) << "\n";
    cout << "1st: " << *s.find_by_order(1) << "\n";
    cout << "2nd: " << *s.find_by_order(2) << "\n\n\n";

    ordered_set_g s1;
    s1.insert(1);
    s1.insert(3);
    s1.insert(4);
    cout << "{4, 3, 1}\n";
    cout << "nums > 0: " << s1.order_of_key(0) << "\n";
    cout << "nums > 2: " << s1.order_of_key(2) << "\n";
    cout << "nums > 3: " << s1.order_of_key(2) << "\n";
    cout << "nums > 10: " << s1.order_of_key(10) << "\n";
    cout << "0th: " << *s1.find_by_order(0) << "\n";
    cout << "1st: " << *s1.find_by_order(1) << "\n";
    cout << "2nd: " << *s1.find_by_order(2) << "\n\n\n";

    ordered_set_le s2;
    s2.insert(1);
    s2.insert(1);
    s2.insert(3);
    s2.insert(4);
    cout << "{1, 1, 3, 4}\n";
    cout << "nums < 0: " << s2.order_of_key(0) << "\n";
    cout << "nums < 2: " << s2.order_of_key(2) << "\n";
    cout << "nums < 3: " << s2.order_of_key(2) << "\n";
    cout << "nums < 10: " << s2.order_of_key(10) << "\n";
    cout << "0th: " << *s2.find_by_order(0) << "\n";
    cout << "1st: " << *s2.find_by_order(1) << "\n";
    cout << "2nd: " << *s2.find_by_order(2) << "\n";
}
