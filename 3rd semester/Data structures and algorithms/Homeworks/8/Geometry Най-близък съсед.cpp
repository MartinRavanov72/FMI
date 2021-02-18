#include <bits/stdc++.h>


using namespace std;

struct point_comparator{
    long long dimension;

    point_comparator(long long dimension = 0): dimension(dimension){}

    const bool operator()(const vector<long long>& point1, const vector<long long>& point2) const{
        return point1[dimension] < point2[dimension];
    }
};

class kd_tree{
    private:
    struct kd_node{
        vector<long long> point;

        long long axis;

        kd_node* left;
        kd_node* right;

        kd_node(const vector<long long>& point): point(point){}
    };

    long long k;
    kd_node* root;

    kd_node* build(vector<vector<long long>>& points, long long from, long long to, long long axis){
        if(from > to){
            return nullptr;
        }

        long long mid = (from + to) / 2;
        nth_element(points.begin() + from,
            points.begin() + mid,
            points.begin() + to + 1,
            point_comparator(axis));

        kd_node* node = new kd_node(points[mid]);
        node->axis = axis;
        node->left = build(points, from, mid - 1, (axis + 1) % k);
        node->right = build(points, mid + 1, to, (axis + 1) % k);

        return node;
    }

    double getDistance(const vector<long long>& point1,const vector<long long>& point2){
        double distance = 0.0;

        for(long long i = 0; i < k; i++){
            distance += ((double)point1[i] - point2[i]) * ((double)point1[i] - point2[i]);
        }

        return (distance);
    }

    public:
    kd_tree(vector<vector<long long>> points, long long dimensions){
        k = dimensions;
        root = build(points, 0, points.size() - 1, 0);
    }

    double closest_point(const vector<long long>& point){
        double distance = std::numeric_limits<double>::max();
        nearest(point, root, distance);
        return sqrt(distance);
    }

    void nearest(const vector<long long>& point, kd_node* currentNode, double& best){
        if(!currentNode){
            return;
        }

        double distance = getDistance(point, currentNode->point);

        double dx = point[currentNode->axis] - currentNode->point[currentNode->axis];
        
        if(distance < best){
            best = distance;
        }

        kd_node* near = dx <= 0 ? currentNode->left : currentNode->right;
        kd_node* far = dx <= 0 ? currentNode->right : currentNode->left;

        nearest(point, near, best);

        if((dx * dx) >= best){
            return;
        }

        nearest(point, far, best);
    }
};

vector<long long> read_point(long long k){
    vector<long long> point(k);
    for(long long i = 0; i < k; i++){
        cin >> point[i];
    }
    return point;
}

void solve(){
    long long n, k;
    cin >> n >> k;

    vector<vector<long long>> points;
    for(long long i = 0; i < n; i++){
        points.push_back(read_point(k));
    }

    kd_tree tree(points, k);

    long long q;
    cin >> q;

    cout << fixed << setprecision(3);

    for(long long i = 0; i < q; i++){
        cout << tree.closest_point(read_point(k)) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}


