use proconio::input;
use std::collections::BTreeSet;
fn main() {
    input! {
        n: usize,
        a: [u32; n]
    }
    let mut vals = BTreeSet::new();
    for val in a {
        vals.insert(val);
    }

    let mut mex = 0;
    loop {
        if !vals.contains(&mex) {
            println!("{}", mex);
            return;
        }
        mex += 1;
    }
}
