let mean lst =
  let sum = List.fold_left ( + ) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 0 then
    let mid1 = List.nth sorted ((len / 2) - 1) in
    let mid2 = List.nth sorted (len / 2) in
    (float_of_int (mid1 + mid2)) /. 2.0
  else
    float_of_int (List.nth sorted (len / 2))

let mode lst =
  let sorted = List.sort compare lst in
  let counts =
    List.fold_left
      (fun acc x ->
         let count = try List.assoc x acc with Not_found -> 0 in
         (x, count + 1) :: List.remove_assoc x acc)
      [] sorted
  in
  let max_count = List.fold_left (fun acc (_, c) -> max acc c) 0 counts in
  List.map fst (List.filter (fun (_, c) -> c = max_count) counts)

(* Example usage *)
let () =
  let data = [1; 2; 3; 3; 3; 4; 5; 6; 7; 8; 9] in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  Printf.printf "Mode(s): %s\n"
    (String.concat " " (List.map string_of_int (mode data)))
