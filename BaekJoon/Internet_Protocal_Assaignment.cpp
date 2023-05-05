#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
using namespace std;
#define NUMBER_OF_HOSTS first 
#define BIT_MORE_THAN_HOSTS second
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

typedef int bit;
typedef int host;

struct subnet_info
{
private :
	int subnet_;
	string network_id_;
	int subnet_mask_;
	string range_;
	string broad_cast_; 
public:
	subnet_info() : subnet_{ 0 }, network_id_{ 0 }, subnet_mask_{ 0 }, range_{ 0 }, broad_cast_{ 0 } {}
	subnet_info(const int subnet, const string& network_id, const int subnet_mask, const string& range, const string& broad_cast)
	{
		this->subnet_ = subnet;
		this->network_id_ = network_id;
		this->subnet_mask_ = subnet_mask;
		this->range_ = range;
		this->broad_cast_ = broad_cast;
	}
	int get_subnet() const
	{
		return subnet_;
	}
	string get_network_id() const
	{
		return network_id_;
	}
	int get_subnet_mask() const
	{
		return subnet_mask_;
	}
	string get_range() const
	{
		return range_;
	}
	string get_broad_cast() const
	{
		return broad_cast_;
	}

};

void input_variables(string& input_network_ip, int& subnet_mask, int& number_of_subnets);
int calculate_bit_of_hosts(int number_of_hosts);
void input_hosts(vector<pair<host, bit>>& hosts);
void split_network_ip(bitset<8> network_ip[4], string input_network_ip, const string& delimiter);
void calculate_subnets(vector<subnet_info>& subnets, bitset<8> ip[4], const vector<pair<host, bit>>& hosts);
void print_result(const vector<subnet_info>& subnets);
string get_ip(bitset<8> ip[4]);
string get_range(bitset<8> ip[4], int bit_to_dec);
void check_bit(bitset<8> ip[4], int bit_to_add);

int main()
{
	FAST_IO;

	string input_network_ip;
	int subnet_mask, number_of_subnets;
	input_variables(input_network_ip, subnet_mask, number_of_subnets);

	bitset<8> network_ip[4];
	vector<pair<host, bit>> hosts(number_of_subnets);
	vector<subnet_info> subnets(number_of_subnets);

	split_network_ip(network_ip, input_network_ip, ".");

	input_hosts(hosts);
	sort(hosts.begin(), hosts.end(), greater<>());

	calculate_subnets(subnets, network_ip, hosts);

	print_result(subnets);
	return 0;
}

void input_variables(string& input_network_ip, int& subnet_mask, int& number_of_subnets)
{
	cout << "Input Network Address : ";
	cin >> input_network_ip;
	cout << "Input Subnet Mask : ";
	cin >> subnet_mask;
	cout << "How many subnets : ";
	cin >> number_of_subnets;
}

int calculate_bit_of_hosts(const int number_of_hosts)
{
	int bit = 1;
	while ((1 << bit) - 2 < number_of_hosts)
	{
		bit++;
	}
	return bit;
}

void input_hosts(vector<pair<host, bit>>& hosts)
{
	int idx = 1;
	for (pair<host, bit>& host : hosts)
	{
		cout << "Subnet " << idx++ << " : How many hosts : ";
		int number_of_hosts; cin >> number_of_hosts;
		host.NUMBER_OF_HOSTS = number_of_hosts;
		host.BIT_MORE_THAN_HOSTS = calculate_bit_of_hosts(number_of_hosts);
	}
}

void split_network_ip(bitset<8> network_ip[4], string input_network_ip, const string& delimiter)
{
	vector<int>::size_type pos = 0;
	string token = const_cast<char*>("");
	int i = 0;
	while ((pos = input_network_ip.find(delimiter)) != string::npos) {
		token = input_network_ip.substr(0, pos);
		network_ip[i++] = stoi(token);
		input_network_ip.erase(0, pos + delimiter.length());
	}
	network_ip[i] = stoi(input_network_ip);
}

void check_bit(bitset<8> ip[4], const int bit_to_add)
{
	unsigned long tmp[4] = { 0,0,0,ip[3].to_ulong() + bit_to_add };
	for (int i = 3; i >= 0; i--)
	{
		ip[i] = tmp[i] % 256;
		if(i > 0)
		{
			tmp[i - 1] = ip[i - 1].to_ulong() + tmp[i] / 256;
		}
	}
}

string get_ip(bitset<8> ip[4])
{
	string tmp;
	for (int i = 0; i < 4; i++)
	{
		tmp += to_string(ip[i].to_ulong()) + ".";
	}
	tmp.pop_back();
	check_bit(ip, 1);
	return tmp;
}

string get_range(bitset<8> ip[4], const int bit_to_dec)
{
	string tmp;
	tmp += get_ip(ip) + " - ";
	check_bit(ip, bit_to_dec - 4);
	tmp += get_ip(ip);
	return tmp;
}

void calculate_subnets(vector<subnet_info>& subnets, bitset<8> ip[4], const vector<pair<host, bit>>& hosts)
{
	for (int i = 0; i < static_cast<int>(hosts.size()); i++)
	{
		const int bit_to_dec = 1 << hosts[i].BIT_MORE_THAN_HOSTS;

		string network_id = get_ip(ip);
		const string range = get_range(ip, bit_to_dec) + "(" + to_string(bit_to_dec - 2) + "EA)";
		const string broad_cast = get_ip(ip);
		const int subnet_mask = 32 - hosts[i].BIT_MORE_THAN_HOSTS;

		subnets[i] = subnet_info(i + 1, network_id, subnet_mask, range, broad_cast);
	}
}

void print_result(const vector<subnet_info>& subnets)
{
	cout << "\n\t=== Subnet Calculation Result by YooHeeJoon ===\n\n";
	cout << "Subnet\tNetwork ID\tSubnet Mask\t\t\tRange\t\t\tBroadcast\n";
	for (const subnet_info& subnet : subnets)
	{
		cout << subnet.get_subnet() << '\t'
			<< subnet.get_network_id() << "\t \t"
			<< subnet.get_subnet_mask() << '\t'
			<< subnet.get_range() << "\t"
			<< subnet.get_broad_cast() << '\n';
	}
}









// check_bit()
//const unsigned long ip3 = (ip[3].to_ulong() + bit_to_add) % 256;
//const unsigned long ip2 = (ip[2].to_ulong() + ((ip[3].to_ulong() + bit_to_add) / 256)) % 256;
//const unsigned long ip1 = (ip[1].to_ulong() + (ip[2].to_ulong() + ((ip[3].to_ulong() + bit_to_add) / 256)) / 256) % 256;
//const unsigned long ip0 = (ip[0].to_ulong() + (ip[1].to_ulong() + (ip[2].to_ulong() + ((ip[3].to_ulong() + bit_to_add) / 256)) / 256) / 256) % 256;
//ip[3] = ip3;
//ip[2] = ip2;
//ip[1] = ip1;
//ip[0] = ip0;


/*
 192.168.0.0
 24
 4
 100
 60
 30
 12


192.168.0.0
16
4
600
360
120
100
 */