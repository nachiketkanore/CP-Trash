use proconio::input;
fn main() {
    input! {
        n: usize,
        m: usize,
        want: [[i32; m]; n]
    }
    let first = want[0][0];
    let last = ((first + 6) / 7) * 7;
    let cols = last - first + 1;
    if cols < m as i32 {
        println!("No");
        return;
    }
    let have: Vec<Vec<i32>> = (0..n - 1).fold(
        vec![(first..first + m as i32).collect::<Vec<i32>>()],
        |mut acc, i| {
            acc.push(acc[i].clone().iter().map(|val| val + 7).collect());
            acc
        },
    );
    println!("{}", if want.eq(&have) { "Yes" } else { "No" });
}
