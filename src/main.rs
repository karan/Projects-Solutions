extern crate rand;

use std::io;
use rand::Rng;

fn e_to_dp() {
    let mut rng = rand::thread_rng();
    let e: f64 = rng.gen_range(0.0, 1.0);
    println!("To how many decimal places do you want E");
    let mut out = String::new();
    io::stdin().read_line(&mut out).expect("There was an error");
    let out_num = out.trim().parse::<usize>();
    match out_num {
        Ok(_g) => {let out_num = out_num.unwrap(); println!("PI to {} decimal places = {:.*}", out_num, out_num, e)},
        Err(err) => println!("There was an error - {}
        - Maybe you did not enter a number", err)
    }
}

fn main() {
    println!("Hello, world!");
    e_to_dp();
}
