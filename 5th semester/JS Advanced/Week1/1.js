// function quicksort(arr, start, end) {
//     if (start < end && start >= 0 && end >= 0) {
//         let pivot = choosePivot(arr, start, end);
//         quicksort(arr, start, pivot);
//         quicksort(arr, pivot + 1, end);
//     }
// }

// function choosePivot(arr, start, end) {
//     let pivot = arr[Math.floor((start + end) / 2)];
//     let left = start - 1;
//     let right = end + 1;

//     while (true) {
//         do {
//             left++;
//         } while (arr[left] < pivot)

//         do {
//             right--;
//         } while (arr[right] > pivot)

//         if (left >= right) {
//             return right;
//         }

//         [arr[left], arr[right]] = [arr[right], arr[left]];
//     }
// }

// let arr = [23,5, 236, 26, 347, 659, 76, 463, 236, 15, 2635867]
// quicksort(arr, 0, arr.length - 1);
// console.log(arr);






let desired = 100, percent = 6, value = 2000, tax = 5, months = 24, currentAllMonth = 0;
percent /= 1200;
console.log(canBePaid(value));

// function calculateInstallment(currValue) {
//     let yearlyAmount = currValue;
//     let cnt = 0;

//     while (currValue > 0 && cnt < 12) {
//         currValue -= yearlyAmount * percent;
//         currValue -= tax;
//         if()
//         cnt++;
//     }

//     if (cnt == 12) {
//         return cnt - 1 + calculateInstallment(currValue);
//     } else {
//         return cnt - 1;
//     }
// }

function canBePaid(toBePaid) {
    let yearlyAmount = toBePaid;
    let currYearlyMonth = 0;

    while (toBePaid > 0 && currYearlyMonth < 12 && currentAllMonth <= months) {
        if (desired < yearlyAmount * percent + tax) {
            return false;
        }

        toBePaid -= (desired - (yearlyAmount * percent + tax));
        currYearlyMonth++;
        currentAllMonth++;
    }

    if (currYearlyMonth == 12) {
        return canBePaid(toBePaid);
    } else if (currentAllMonth > months) {
        return false;
    }

    return true;
}