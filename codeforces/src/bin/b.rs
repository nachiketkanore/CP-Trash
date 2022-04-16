use proconio::input;
fn main() {
    input! {
        n: usize
    }
    let mut have = vec![0; n];
    let mut want = vec![1; n];
    want[n - 1] = n - 1;
    for _ in 0..n - 1 {
        input! {
            u: usize,
            v: usize
        }
        have[u - 1] += 1;
        have[v - 1] += 1;
    }
    have.sort();
    if have.eq(&want) {
        println!("Yes");
    } else {
        println!("No");
    }
}
