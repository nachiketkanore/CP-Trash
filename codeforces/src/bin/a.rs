use itertools::Itertools;
use proconio::input;
fn main() {
    input! {
       s: String
    }
    println!(
        "{}",
        s.chars().permutations(3).unique().fold(0, |acc, _| acc + 1)
    );
}
