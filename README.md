# C Shopping List Capstone Project

## Objective

The objective of this project was to leverage extensive knowledge of various data structures to create a comprehensive and efficient shopping cart program in C. This application seamlessly integrates multiple data structures to facilitate features such as adding and deleting items, tracking the last seen item, and querying specific products. My implementation showcases a profound grasp of these data structures and their practical application in designing a user-friendly and robust shopping cart system. This integration highlights my ability to effectively apply theoretical concepts to real-world programming challenges, thereby delivering a technically sound and highly functional solution.

## Motivation

The motivation behind this project was to address the challenge of managing shopping lists efficiently. In many existing systems, the ability to quickly add, search, and delete items, while maintaining an intuitive user interface, is often lacking. By incorporating advanced data structures, this project aims to demonstrate how such structures can significantly improve the performance and usability of a shopping cart system. The goal was to create a solution that not only meets the functional requirements but also showcases the application of theoretical knowledge in practical scenarios.

## What It Does

The C Shopping List Capstone Project is designed to manage a shopping cart efficiently by:

- Allowing users to add items to the cart.
- Enabling deletion of items from the cart.
- Keeping track of the last seen item.
- Providing efficient search capabilities for specific products.
- Displaying the contents of the cart along with the total cost.

## Data Flow

1. **Initialization**: The program starts with an empty shopping cart.
2. **Adding Items**: When a product is added via the Push function, it is placed in both the doubly linked list (for cart management) and the binary search tree (for efficient searching).
3. **Displaying Items**: The Display function iterates over the doubly linked list to print each product's name and cost, also calculating the total cost.
4. **Searching/Deleting Items**: Products can be searched or deleted through the Search function. The action character ('s' for search, 'd' for delete) determines the operation.
5. **Removing Items**: The Pop and Qdelete functions mimic stack and queue behaviors to remove products from the cart.

## Prioritization

### Tackled:

- **Core Functionality**: Ensuring the primary operations of adding, deleting, and searching items are robust and efficient.
- **Data Structure Integration**: Seamlessly integrating multiple data structures to handle different aspects of cart management.
- **User Interface**: Providing a menu-driven interface for easy interaction.

### Not Tackled:

- **Advanced Features**: Features like product categories, quantity management, or user authentication were not implemented to keep the project focused on showcasing data structure application.
- **Error Handling**: While basic error handling is in place, more extensive validation and handling of edge cases were not prioritized.

## Skills and Methodologies

This project utilizes various skills and methodologies, including:

- **Data Structures**: Implementing linked lists, stacks, queues, circular linked lists, and binary search trees.
- **Dynamic Memory Allocation**: Efficiently managing memory for the data structures.
- **Algorithm Design**: Designing algorithms for adding, deleting, and searching items.
- **User Interface Design**: Creating a menu-driven interface for user interaction.
- **Problem Solving**: Addressing and solving issues related to data structure integration and efficient data management.

## Notable Features

- **Efficient Search**: Using a binary search tree for quick lookup of products.
- **Undo Last Action**: Utilizing stack operations to allow undoing the last added item.
- **FIFO Deletion**: Implementing queue-like behavior for removing the first added item.

## Lessons Learned

- **Integration Challenges**: Integrating multiple data structures into a single application requires careful planning and understanding of their individual behaviors and interactions.
- **Memory Management**: Proper dynamic memory allocation and deallocation are crucial to prevent memory leaks and ensure efficient program execution.
- **User Experience**: A simple and intuitive user interface significantly enhances the usability of the application.

## Problems Faced

- **Complex Data Integration**: Initially, integrating different data structures into a cohesive system was challenging. This was solved by modularizing the code and ensuring clear interfaces between different components.
- **Memory Leaks**: During development, memory leaks were encountered due to improper deallocation of memory. This was addressed by implementing thorough testing and using tools like Valgrind to identify and fix leaks.

## Testing

To test the application, run the executable file and interact with the menu-driven interface to add, delete, search, and display items in the shopping cart.

## Images
![Home Screen](imgages/1.png)
![Demo Screen](imgages/2.png)


---

This project serves as a comprehensive demonstration of applying advanced data structures to solve real-world problems, showcasing both technical skills and problem-solving abilities.
