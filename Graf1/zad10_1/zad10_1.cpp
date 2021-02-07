// zad10_1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>

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

vector<vector<int>> BFS(vector<vector<int>>& values_vector)
{
	vector<int> visited;
	vector<vector<int>> visited_vector;
	queue<int> q;
	int start = 1;
	int node = start;
	int val;
	for (int i = 0; i < values_vector.size(); i++)
	{
		q.push(1);
		visited.push_back(1);
		node = 1;
		while (!q.empty())
		{
			node = q.front();
			q.pop();
			while (val = find_neighbour(node, values_vector[i], visited))
			{
				visited.push_back(val);
				q.push(val);
			}

		}
		visited_vector.push_back(visited);
		visited.clear();
	}
	return visited_vector;
}


vector<vector<int>> DFS(vector<vector<int>>& values_vector)
{
	vector<int> visited;
	vector<vector<int>> visited_vector;
	int start = 1;
	int node = start;
	stack<int> s;
	for (int i = 0; i < values_vector.size(); i++)
	{
		s.push(0);
		node = 1;
		while (!s.empty())
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

				s.push(node);
				if (!check_value(node, visited))
				{
					visited.push_back(node);
				}

				node = tmp;
			}
		}
		visited_vector.push_back(visited);
		visited.clear();
		for (int i = 0; i < s.size(); i++)
		{
			s.pop();
		}
	}
	return visited_vector;
}

void view(vector<vector<int>> DFS, vector<vector<int>> BFS)
{
	for (int i = 0; i < DFS.size(); i++) {
		cout << "Graf nr " << i +1 << endl;
		cout << "DFS: ";
		for (int j = 0; j < DFS[i].size(); j++)
		{
			cout << DFS[i][j] << " ";
		}
		cout << endl;
		cout << "BFS: ";
		for (int j = 0; j < BFS[i].size(); j++)
		{
			cout << BFS[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<int>> values_vector;
	vector<vector<int>> BFS_result;
	vector<vector<int>> DFS_result;
	read_data(values_vector);
	DFS_result =DFS(values_vector);
	BFS_result =BFS(values_vector);
	view(DFS_result, BFS_result);
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
