#include "vector_caluculation.h"
#include <stdio.h>

// --- テスト用のヘルパー関数 ---

// doubleの比較
bool approx_equal_double(double a, double b) {
    return fabs(a - b) < 1e-6;
}

// t_vec3の比較
bool approx_equal_vec(t_vec3 v1, t_vec3 v2) {
    return approx_equal_double(v1.x, v2.x) &&
           approx_equal_double(v1.y, v2.y) &&
           approx_equal_double(v1.z, v2.z);
}

// テスト結果の表示
void run_test(const char *name, bool success) {
    printf("[Test: %-25s] ", name);
    if (success) {
        printf("\033[32m[OK]\033[0m\n");
    } else {
        printf("\033[31m[FAIL]\033[0m\n");
    }
}

// --- メインのテスト関数 ---

int main(void) {
    printf("--- Testing Vector Utilities ---\n\n");

    // vec_new
    t_vec3 v_new = vec_new(1.0, -2.0, 3.5);
    run_test("vec_new", v_new.x == 1.0 && v_new.y == -2.0 && v_new.z == 3.5);

    // テスト用のベクトル
    t_vec3 v1 = vec_new(1, 2, 3);
    t_vec3 v2 = vec_new(4, 5, 6);

    // vec_add
    t_vec3 v_add = vec_add(v1, v2);
    run_test("vec_add", approx_equal_vec(v_add, vec_new(5, 7, 9)));

    // vec_sub
    t_vec3 v_sub = vec_sub(v1, v2);
    run_test("vec_sub", approx_equal_vec(v_sub, vec_new(-3, -3, -3)));

    // vec_scalar_mul
    t_vec3 v_mul = vec_scalar_mul(v1, 3.0);
    run_test("vec_scalar_mul", approx_equal_vec(v_mul, vec_new(3, 6, 9)));
    
    // vec_scalar_div
    t_vec3 v_div = vec_scalar_div(vec_new(4, -8, 12), 2.0);
    run_test("vec_scalar_div", approx_equal_vec(v_div, vec_new(2, -4, 6)));

    // vec_dot
    double dot_p = vec_dot(v1, v2);
    run_test("vec_dot", approx_equal_double(dot_p, 1*4 + 2*5 + 3*6)); // 4 + 10 + 18 = 32

    // vec_cross
    t_vec3 i = vec_new(1, 0, 0);
    t_vec3 j = vec_new(0, 1, 0);
    t_vec3 k = vec_new(0, 0, 1);
    t_vec3 cross_p = vec_cross(i, j);
    run_test("vec_cross (i x j = k)", approx_equal_vec(cross_p, k));
    cross_p = vec_cross(j, i);
    run_test("vec_cross (j x i = -k)", approx_equal_vec(cross_p, vec_new(0, 0, -1)));

    // vec_length & vec_length_squared
    t_vec3 v_len_test = vec_new(3, 4, 0);
    run_test("vec_length", approx_equal_double(vec_length(v_len_test), 5.0));
    run_test("vec_length (zero vec)", approx_equal_double(vec_length(vec_new(0,0,0)), 0.0));

    // vec_normalize
    t_vec3 v_norm_test = vec_new(5, 0, 0);
    t_vec3 normalized_v = vec_normalize(v_norm_test);
    run_test("vec_normalize (result)", approx_equal_vec(normalized_v, vec_new(1, 0, 0)));
    run_test("vec_normalize (length is 1)", approx_equal_double(vec_length(normalized_v), 1.0));
    
    // ゼロベクトルの正規化
    t_vec3 zero_vec = vec_new(0, 0, 0);
    normalized_v = vec_normalize(zero_vec);
    run_test("vec_normalize (zero vec)", approx_equal_vec(normalized_v, zero_vec));

    printf("\n--- All tests finished ---\n");
    return 0;
}
