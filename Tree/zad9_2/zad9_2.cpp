#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <string>

using namespace std;

void read_data(vector<vector<int>> &values_vector) {
	int z = 0, w = 0, k = 0;
	int w_val = 0, k_val = 0;

	vector<int> data;
	set<int> set;

	cin >> z;
	for (int i = 0; i < z; i++)
	{
		cin >> w >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> w_val >> k_val;
			data.push_back(w_val);
			data.push_back(k_val);
		}
		values_vector.push_back(data);
		data.clear();
	}
}

bool check_value(int value, vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == value)
			return true;
	}
	return false;
}

vector<int> check_consistency(vector<vector<int>>& values_vector) {
	vector<int> c_counter;
	int start;
	vector<int> connected_values;
	int counter = 1;
	for (int i = 0; i < values_vector.size(); i++)
	{
		start = 1;
		connected_values.push_back(1);
		counter = 1;
		for (int j = 0; j < values_vector[i].size(); j += 2)
		{
			if (values_vector[i][j] != start)
			{
				if (!check_value(values_vector[i][j], connected_values)) {
					counter++;
					connected_values.push_back(values_vector[i][j]);
				}
				start = values_vector[i][j];
			}
			if (!check_value(values_vector[i][j + 1], connected_values))
			{
				connected_values.push_back(values_vector[i][j + 1]);
			}
		}
		c_counter.push_back(counter);
		connected_values.clear();
	}
	return c_counter;
}

int find_neighbour(int node, vector<int> &nodes, vector<int> &visited)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i] == node)
		{
			if (i % 2 == 0)
			{
				if (!check_value(nodes[i + 1], visited)) {
					return nodes[i + 1];
				}
			}
			else
			{
				if (!check_value(nodes[i - 1], visited)) {
					return nodes[i - 1];
				}
			}
		}
	}
	return 0;
}

bool is_cycle(int node, vector<int>& nodes, vector<int>& visited, int prev)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i] == node)
		{
			if (i % 2 == 0)
			{
				if (nodes[i + 1] != prev & check_value(nodes[i + 1], visited))
				{
					return true;
				}
			}
			else
			{
				if (nodes[i - 1] != prev & check_value(nodes[i - 1], visited))
				{
					return true;
				}
			}
		}
	}
	return false;
}

vector<bool> check_cycle(vector<vector<int>>& values_vector)
{
	vector<bool> cycle;
	bool cycle_flag;
	vector<int> visited;
	int start = 1;
	int node = start;
	stack<int> s;
	for (int i = 0; i < values_vector.size(); i++)
	{
		cycle_flag = false;
		s.push(1);
		visited.push_back(1);
		node = 1;
		while (!s.empty())
		{
			if (is_cycle(node, values_vector[i], visited, s.top()))
			{
				cycle_flag = true;
				break;

			}
			else
			{
				int tmp = find_neighbour(node, values_vector[i], visited);
				if (tmp == 0)
				{
					if (!check_value(node, visited))
					{
						visited.push_back(node);
					}
					node = s.top();
					s.pop();
				}
				else
				{
					if (node != start)
					{
						s.push(node);
						if (!check_value(node, visited))
						{
							visited.push_back(node);
						}
					}
					node = tmp;

				}
			}
		}
		cycle.push_back(cycle_flag);
		visited.clear();
		for (int i = 0; i < s.size(); i++)
		{
			s.pop();
		}
	}
	return cycle;
}

void view(vector<bool> &cycle, vector<int> & consistency) {
	for (int i = 0; i < cycle.size(); i++)
	{
		string s;
		if (consistency[i] == 1)
		{
			s = "TAK";
		}
		else {
			s = "NIE";
		}
		string s2;
		if (cycle[i])
		{
			s2 = "TAK";
		}
		else {
			s2 = "NIE";
		}
		cout << "Graf " << i + 1 << endl << "Spojny ";
		cout << s << " (" << consistency[i] << ")" << endl << "Cykle " << s2 << endl;
	}
}

int main()
{
	vector<vector<int>> values_vector;
	vector<bool> cycle;
	vector<int> consistency;
	read_data(values_vector);
	consistency = check_consistency(values_vector);
	cycle = check_cycle(values_vector);
	view(cycle, consistency);
	return 0;
}

