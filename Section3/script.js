document.addEventListener('DOMContentLoaded', () => {
    const taskForm = document.getElementById('taskForm');
    const taskTitle = document.getElementById('taskTitle');
    const taskDescription = document.getElementById('taskDescription');
    const taskPriority = document.getElementById('taskPriority');
    const taskList = document.getElementById('taskList');
    const submitButton = document.getElementById('submitButton');
    const cancelButton = document.getElementById('cancelButton');

    let editingIndex = -1;
    const tasks = JSON.parse(localStorage.getItem('tasks')) || [];

    function saveTasks() {
        localStorage.setItem('tasks', JSON.stringify(tasks));
    }

    function renderTasks() {
        tasks.sort((a, b) => {
            const priorityOrder = { low: 3, medium: 2, high: 1 };
            if (a.completed !== b.completed) {
                return a.completed ? 1 : -1;
            }
            return priorityOrder[a.priority] - priorityOrder[b.priority];
        });

        taskList.innerHTML = '';
        tasks.forEach((task, index) => {
            const taskItem = document.createElement('div');
            taskItem.className = `task-item ${task.priority} ${task.completed ? 'completed' : ''}`;
            taskItem.setAttribute('data-index', index); // Set index on the task item
            taskItem.innerHTML = `
                <div class="task-content">
                    <h5>${task.title}</h5>
                    <p>${task.description}</p>
                </div>
                <div class="task-actions">
                    <button class="btn btn-warning btn-sm edit">
                        <i class="fas fa-edit"></i>
                    </button>
                    <button class="btn btn-danger btn-sm delete">
                        <i class="fas fa-trash"></i>
                    </button>
                    <button class="btn btn-success btn-sm toggle">
                        ${task.completed ? '<i class="fas fa-undo"></i>' : '<i class="fas fa-check"></i>'}
                    </button>
                </div>
            `;
            taskList.appendChild(taskItem);
        });
    }

    taskForm.addEventListener('submit', (e) => {
        e.preventDefault();
        const title = taskTitle.value.trim();
        const description = taskDescription.value.trim();
        const priority = taskPriority.value;

        if (title && description) {
            if (editingIndex >= 0) {
                // Edit mode
                tasks[editingIndex] = {
                    title,
                    description,
                    priority,
                    completed: tasks[editingIndex].completed
                };
                editingIndex = -1;
                submitButton.textContent = 'Add Task';
                submitButton.classList.remove('btn-edit');
                cancelButton.style.display = 'none';
            } else {
                // Add new task
                tasks.push({
                    title,
                    description,
                    priority,
                    completed: false
                });
            }
            saveTasks();
            renderTasks();
            taskForm.reset();
        }
    });

    taskForm.addEventListener('reset', () => {
        if (editingIndex >= 0) {
            submitButton.textContent = 'Add Task';
            submitButton.classList.remove('btn-edit');
            cancelButton.style.display = 'none';
        }
    });

    taskList.addEventListener('click', (e) => {
        const taskItem = e.target.closest('.task-item');
        if (!taskItem) return; // If the target is not within a task-item, exit

        const index = parseInt(taskItem.getAttribute('data-index'), 10);

        if (e.target.closest('.delete')) {
            // Delete task
            taskItem.classList.add('poof');
            taskItem.addEventListener('animationend', () => {
                tasks.splice(index, 1);
                saveTasks();
                renderTasks();
            }, { once: true });
        } else if (e.target.closest('.edit')) {
            // Edit task
            const task = tasks[index];
            taskTitle.value = task.title;
            taskDescription.value = task.description;
            taskPriority.value = task.priority;
            editingIndex = index; // Set edit mode
            submitButton.textContent = 'Edit Task';
            submitButton.classList.add('btn-edit');
            cancelButton.style.display = 'inline-block';
        } else if (e.target.closest('.toggle')) {
            // Toggle completed status
            tasks[index].completed = !tasks[index].completed;
            taskItem.classList.add('poof');
            taskItem.addEventListener('animationend', () => {
                saveTasks();
                renderTasks();
            }, { once: true });
        }
    });

    cancelButton.addEventListener('click', () => {
        taskForm.reset();
        editingIndex = -1;
        submitButton.textContent = 'Add Task';
        submitButton.classList.remove('btn-edit');
        cancelButton.style.display = 'none';
    });

    renderTasks();
});
