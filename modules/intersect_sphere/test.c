#include "intersect_sphere.h" // 共通のヘッダーをインクルード
#include <stdio.h>

// --- テスト用のヘルパー関数 ---

// 浮動小数点数の比較
bool approx_equal(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

// テスト結果の表示
void run_test(const char *name, double expected, double got)
{
    printf("[Test: %s]\n", name);
    printf("  - Expected: %.6f\n", expected);
    printf("  - Got:      %.6f\n", got);
    if (approx_equal(expected, got))
    {
        printf("  \033[32m[OK]\033[0m\n\n");
    }
    else
    {
        printf("  \033[31m[FAIL]\033[0m\n\n");
    }
}

// --- メインのテスト関数 ---

int main(void)
{
    t_sphere sphere;
    t_ray    ray;
    double   t;

    printf("--- Testing intersect_sphere() ---\n\n");

    // テストケース 1: レイが球を正面から貫通 (2つの交点)
    sphere = (t_sphere){.center = vec_new(0, 0, 10), .diameter = 4.0}; // r=2
    ray = (t_ray){.origin = vec_new(0, 0, 0), .direction = vec_new(0, 0, 1)};
    t = intersect_sphere(ray, sphere);
    run_test("Ray intersects sphere from the front (2 hits)", 8.0, t);

    // テストケース 2: レイが球の端に接する (1つの交点)
    sphere = (t_sphere){.center = vec_new(0, 0, 10), .diameter = 4.0}; // r=2
    ray = (t_ray){.origin = vec_new(2, 0, 0), .direction = vec_new(0, 0, 1)};
    t = intersect_sphere(ray, sphere);
    run_test("Ray is tangent to the sphere (1 hit)", 10.0, t);

    // テストケース 3: レイが球を完全に外れる (交差なし)
    sphere = (t_sphere){.center = vec_new(0, 0, 10), .diameter = 4.0}; // r=2
    ray = (t_ray){.origin = vec_new(3, 0, 0), .direction = vec_new(0, 0, 1)};
    t = intersect_sphere(ray, sphere);
    run_test("Ray misses the sphere (no hit)", INFINITY, t);

    // テストケース 4: レイが球の内部から始まる
    sphere = (t_sphere){.center = vec_new(0, 0, 10), .diameter = 4.0}; // r=2
    ray = (t_ray){.origin = vec_new(0, 0, 10), .direction = vec_new(0, 0, 1)};
    t = intersect_sphere(ray, sphere);
    run_test("Ray starts inside the sphere", 2.0, t);

    // テストケース 5: 球がレイの後方にある (tが負になるケース)
    sphere = (t_sphere){.center = vec_new(0, 0, -10), .diameter = 4.0}; // r=2
    ray = (t_ray){.origin = vec_new(0, 0, 0), .direction = vec_new(0, 0, 1)};
    t = intersect_sphere(ray, sphere);
    run_test("Sphere is behind the ray (negative t)", INFINITY, t);

    // テストケース 6: レイの始点が球の表面上にある
    sphere = (t_sphere){.center = vec_new(0, 0, 10), .diameter = 4.0}; // r=2
    ray = (t_ray){.origin = vec_new(0, 0, 8), .direction = vec_new(0, 0, 1)};
    t = intersect_sphere(ray, sphere);
    run_test("Ray starts on the sphere surface", 4.0, t);
    
    // ... 他のテストケースも同様 ...

    printf("--- All tests finished ---\n");
    return (0);
}
