#include "../Vector.hpp"
#include <vector>

template <typename T, typename L1, typename L2>
void print_temp(L1 &x, L2 &y)
{
	std::cout << "----------mine:----------\n";
	for (typename L1::iterator it = x.begin(); it != x.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n----------syst:----------\n";
	for (typename L2::iterator it = y.begin(); it != y.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n----------e----------\n";
}

void test_vector()
{
	ft::Vector<int> mvector;
	ft::Vector<int> mvector2;

	std::vector<int> vector;
	std::vector<int> vector2;

	mvector.push_back(1);
	mvector.push_back(2);
	mvector.push_back(3);
	mvector.push_back(4);
	mvector.push_back(5);

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);

	/* =====================> Copy 1 */

	// ft::Vector<int>		mvector3(mvector);
	// std::vector<int>		vector3(vector);

	// std::cout << mvector3.size() << std::endl;
	// std::cout << vector3.size() << std::endl;

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector3, vector3);

	/* =====================> Push test */

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);

	/* =====================> Pop test */

	// mvector.pop_back();
	// mvector.pop_back();

	// vector.pop_back();
	// vector.pop_back();

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);

	/* =====================> Size test */

	// std::cout << "mine: " << mvector.size() << std::endl;
	// std::cout << "orgn: " << vector.size() << std::endl;

	/* =====================> Max Size test */

	// std::cout << "mine: " << mvector.max_size() << std::endl;
	// std::cout << "orgn: " << vector.max_size() << std::endl;

	/* =====================> Resize test */

	// mvector.resize(2);
	// vector.resize(2);

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);

	// mvector.resize(5, 100);
	// vector.resize(5, 100);

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);

	/* =====================> Capacity test */

	// std::cout << mvector.capacity() << std::endl;
	// std::cout << vector.capacity() << std::endl;

	/* =====================> Reserve test */

	// mvector.reserve(20);
	// vector.reserve(20);

	// std::cout << mvector.capacity() << std::endl;
	// std::cout << vector.capacity() << std::endl;

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);

	/* =====================> Operator [] */

	// std::cout << mvector[1] << std::endl;
	// std::cout << vector[1] << std::endl;

	/* =====================> At test */

	// std::cout << mvector.at(1) << std::endl;
	// std::cout << vector.at(1) << std::endl;

	/* =====================> Front back test */

	// std::cout << mvector.front() << std::endl;
	// std::cout << vector.front() << std::endl;

	// std::cout << mvector.back() << std::endl;
	// std::cout << vector.back() << std::endl;

	/* =====================> Assign test */
	// mvector.assign(7, 10);
	// vector.assign(7, 10);

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);

	// mvector2.assign(mvector.begin(), mvector.end());

	// vector2.assign(vector.begin(), vector.end());

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector2, vector2);

	/* =====================> Erase test */

	// ft::Vector<int>::iterator it = mvector.begin();
	// std::vector<int>::iterator its = vector.begin();

	// it = mvector.erase(it);
	// it = mvector.erase(it);
	// it = mvector.erase(it);

	// its = vector.erase(its);
	// its = vector.erase(its);
	// its = vector.erase(its);

	// std::cout << *it << std::endl;
	// std::cout << *its << std::endl;

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);

	/* =====================> Erase test 2 */

	// ft::Vector<int>::iterator it = mvector.begin();
	// std::vector<int>::iterator its = vector.begin();

	// it = mvector.erase(mvector.begin() + 2, mvector.end());
	// its = vector.erase(vector.begin() + 2, vector.end());

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);

	/* =====================> Insert test */

	// ft::Vector<int>::iterator it = mvector.begin();
	// std::vector<int>::iterator its = vector.begin();

	// it = mvector.insert(mvector.begin() + 2, 10);
	// its = vector.insert(vector.begin() + 2, 10);

	// std::cout << *it << std::endl;
	// std::cout << *its << std::endl;
	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);

	/* =====================> Insert test 2 */

	// mvector.insert(mvector.begin() + 2, 5, 10);

	// vector.insert(vector.begin() + 2, 5, 10);

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);

	/* =====================> Insert test 3 */

	// mvector2.insert(mvector2.begin(), mvector.begin() + 1, mvector.end());

	// vector2.insert(vector2.begin(), vector.begin() + 1, vector.end());

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector2, vector2);

	/* =====================> Swap test 1 */

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);
	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector2, vector2);

	// mvector.swap(mvector2);
	// vector.swap(vector2);
	// std::cout << "after swap: \n";

	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector, vector);
	// print_temp<int, ft::Vector<int>, std::vector<int> >(mvector2, vector2);


	/* =====================> Operations */

	// std::cout << "**	OPERATORS 	**" << std::endl;
	// bool a;

	// mvector.push_back(1);
	// mvector2.push_back(1);
	// a = mvector == mvector2;
	// std::cout << "mine:	==  	: " << a << std::endl;

	// vector.push_back(1);
	// vector2.push_back(1);
	// a = vector == vector2;
	// std::cout << "orgn:	==  	: " << a << std::endl;

	// a = mvector != mvector2;
	// std::cout << "mine:	!=  	: " << a << std::endl;

	// a = vector != vector2;
	// std::cout << "orgn:	!=  	: " << a << std::endl;

	// mvector.push_back(2);
	// a = mvector > mvector2;
	// std::cout << "mine:	>  	: " << a << std::endl;

	// vector.push_back(2);
	// a = vector > vector2;
	// std::cout << "orgn:	>  	: " << a << std::endl;

	// a = mvector < mvector2;
	// std::cout << "mine:	<  	: " << a << std::endl;

	// a = vector < vector2;
	// std::cout << "orgn:	<  	: " << a << std::endl;

	// mvector2.push_back(2);
	// a = mvector <= mvector2;
	// std::cout << "mine:	<=  	: " << a << std::endl;

	// vector2.push_back(2);
	// a = vector <= vector2;
	// std::cout << "orgn:	<=  	: " << a << std::endl;

	// a = mvector >= mvector2;
	// std::cout << "mine:	>=  	: " << a << std::endl;

	// a = vector >= vector2;
	// std::cout << "orgn:	>=  	: " << a << std::endl;
}