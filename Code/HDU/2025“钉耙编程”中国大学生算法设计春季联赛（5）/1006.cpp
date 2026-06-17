#include <bits/stdc++.h>

using ll = long long;

int d, r, x, y;

void solve() {
	std::cin >> d >> r >> x >> y;

 	double p;
    if (y > d) {
        double dx = x + r;
        double dy = y - d;
        p = hypot(dx, dy);
    } 
    else if (y < -d) {
        double dx = x + r;
        double dy = y + d;
        p = hypot(dx, dy);
    } 
    else {
        p = abs(x + r);
    }

    double q;
    if (y > d) {
        double dx = x - r;
        double dy = y - d;
        q = hypot(dx, dy);
    } 
    else if (y < -d) {
        double dx = x - r;
        double dy = y + d;
        q = hypot(dx, dy);
    } 
    else {
        q = abs(x - r);
    }

    double low = 1e18;
    {
        double dx = x;
        double dy = y - d;
        double db = hypot(dx, dy);
        if (db == 0) {
            low = r;
        } 
        else {
            double odd = (dx * r) / db;
            double ndd = d + (dy * r) / db;
            if (ndd >= d) {
                low = abs(db - r);
            } 
            else {
                double dx1 = x - r, dy1 = y - d;
                double dx2 = x + r;
                low = std::min(hypot(dx1, dy1), hypot(dx2, dy1));
            }
        }
    }

    double up = 1e18;
    {
        double dx = x;
        double dy = y + d;
        double da = hypot(dx, dy);
        if (da == 0) {
            up = r;
        } else {
            double odd = (dx * r) / da;
            double ndd = (dy * r) / da - d;
            if (ndd <= -d) {
                up = abs(da - r);
            } 
            else {
                double dx1 = x - r, dy1 = y + d;
                double dx2 = x + r;
                up = std::min(hypot(dx1, dy1), hypot(dx2, dy1));
            }
        }
    }

    double min = std::min({p, q, low, up});
    std::cout << round(min) << '\n';
}

signed main() {
	std::cin.tie(nullptr) ->
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	int _ = 1;
	std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}