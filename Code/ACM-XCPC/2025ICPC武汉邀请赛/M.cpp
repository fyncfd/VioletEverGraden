#include <bits/stdc++.h>

using i64 = long long;
using db = double;

const db eps = 1E-8;
const db pi = acos(-1.0);

int sgn(db x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

struct point{
    db x, y, z;
    point(){}
    point(db x, db y, db z) : x(x), y(y), z(z){}
    point operator + (point b) {return point(x + b.x, y + b.x, z + b.z);}
    point operator - (point b) {return point(x - b.x, y - b.y, z - b.z);}
    point operator * (db k) {return point(x * k, y * k, z * k);}
    point operator / (db k) {return point(x / k, y / k, z / k);}
    bool operator == (point b) {return sgn(x - b.x) == 0 and sgn(y - b.y) == 0 and sgn(z - b.z) == 0;}
    void cin() {
        std::cin >> x >> y >> z;
    }
};

struct line{
    point p1, p2;
    line(){}
    line(point p1, point p2) : p1(p1), p2(p2){}
};

typedef line segement;
typedef point vector;

db dis(vector a, vector b) {return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));}

db dot(vector a, vector b) {return a.x * b.x + a.y * b.y + a.z * b.z;}

db len(vector a) {return sqrt(dot(a, a));}

vector cross(vector a, vector b) {return point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);}

db dpl(point p, line v) {
    db ab = dis(p, v.p1);
    db as = dis(p, v.p2);
    db bs = dis(v.p2, v.p1);
    db ca = (as * as + ab * ab - bs * bs) / (2 * ab * as);
    db sa = sqrt(1 - ca * ca);
    return as * sa;
}

bool plr(point p, line v) {
    return sgn(len(cross(v.p1 - p, v.p2 - p))) == 0 and sgn(dot(v.p1 - p, v.p2 - p)) == 0;
}

db dps(point p, segement v) {
    if (sgn(dot(p - v.p1, v.p2 - v.p1)) < 0 or sgn(dot(p - v.p2, v.p1 - v.p2)) < 0) {
        return std::min(dis(p, v.p1), dis(p, v.p2));
    }
    return dpl(p, v);
}

void solve() {
    int r;
    std::cin >> r;
    point A, B, C;
    A.cin(), B.cin(), C.cin();
    A.x = r * A.x / sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
    A.y = r * A.y / sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
    A.z = r * A.z / sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
    B.x = r * B.x / sqrt(B.x * B.x + B.y * B.y + B.z * B.z);
    B.y = r * B.y / sqrt(B.x * B.x + B.y * B.y + B.z * B.z);
    B.z = r * B.z / sqrt(B.x * B.x + B.y * B.y + B.z * B.z);
    C.x = r * C.x / sqrt(C.x * C.x + C.y * C.y + C.z * C.z);
    C.y = r * C.y / sqrt(C.x * C.x + C.y * C.y + C.z * C.z);
    C.z = r * C.z / sqrt(C.x * C.x + C.y * C.y + C.z * C.z);
    
}

auto __init__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    __init__();

    int _ = 1;
    for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}