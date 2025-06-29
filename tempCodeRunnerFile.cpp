cout << "Enter base salary: $";
    while (!(cin >> base_salary) || base_salary < 0) {
        cout << "Invalid input. Enter a non-negative base salary: $";
        cin.clear();
        cin.ignore(10000, '\n');
    }