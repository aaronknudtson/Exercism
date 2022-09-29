//
// This is only a SKELETON file for the 'Allergies' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export class Allergies {
  score;
  allergens = {
    eggs: 1,
    peanuts: 2,
    shellfish: 4,
    strawberries: 8,
    tomatoes: 16,
    chocolate: 32,
    pollen: 64,
    cats: 128,
  }

  constructor(score) {
    this.score = score;
  }

  list() {
    let curr = this.score % 256;
    let allergyList = [];
    const list = Object.keys(this.allergens);
    let idx = list.length;
    while (curr > 0) {
      if (curr >= this.allergens[list[idx]]) {
        allergyList.push(list[idx]);
        curr-=this.allergens[list[idx]];
        idx+=1;
      }
      idx--;
    }
    return allergyList.reverse();
  }

  allergicTo(food) {
    return this.list().indexOf(food) !== -1;
  }
}
