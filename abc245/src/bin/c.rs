use proconio::input;

fn abs(val: i32) -> i32 {
    if val < 0 {
        -val
    } else {
        val
    }
}

fn go(
    id: usize,
    first: bool,
    n: &usize,
    k: &i32,
    a: &Vec<i32>,
    b: &Vec<i32>,
    dp: &mut Vec<Vec<i32>>,
) -> bool {
    if id == *n {
        return true;
    }
    let prev = if first { a[id - 1] } else { b[id - 1] };

    if dp[first as usize][id] != -1 {
        return dp[first as usize][id] != 0;
    }

    let mut ans = false;

    if abs(prev - a[id]) <= *k {
        ans |= go(id + 1, true, n, k, a, b, dp);
    }
    if abs(prev - b[id]) <= *k {
        ans |= go(id + 1, false, n, k, a, b, dp);
    }
    dp[first as usize][id] = ans as i32;
    return ans;
}
fn main() {
    input! {
        n: usize,
        k: i32,
        a: [i32; n],
        b: [i32; n],
    }
    let mut dp: Vec<Vec<i32>> = vec![vec![-1; n]; 2];
    let ans = go(1, false, &n, &k, &a, &b, &mut dp) || go(1, true, &n, &k, &a, &b, &mut dp);
    println!("{}", if ans { "Yes" } else { "No" });
}
