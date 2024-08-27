#include<bits/stdc++.h>

using namespace std;

struct NodeType
{
	double weight, value, p;

	bool operator <(const NodeType &s) const
    {
		return p > s.p;
	}
};

int main()
{
	int N, T, i; 
    cin >> N >> T;
    
    double value = 0.0;
    double x[N + 1];
	NodeType A[N + 1];

	for(i = 1; i <= N; i++) 
    {
        cin >> A[i].weight >> A[i].value;
        A[i].p = A[i].value / A[i].weight;
    }

	sort(A + 1, A + N + 1);

	//this is knap function below 
	double weight_left = T;
    i = 1;

	while (A[i].weight < weight_left)
    {
		x[i] = 1;
        weight_left -= A[i].weight;
		value += A[i].value;i++;
	}

	if (weight_left > 0)
    {
		x[i] = weight_left / A[i].weight;
		value += x[i] * A[i].value;
	}

	printf("%.2lf\n", value);
    
    return 0;
}