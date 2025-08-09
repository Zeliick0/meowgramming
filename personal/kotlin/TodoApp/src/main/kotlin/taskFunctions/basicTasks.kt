package todo.taskFunctions
import todo.savingFunctions.*
import java.io.File

fun addTask(file: File) {
    println("Name the task: ");
    val name = readlnOrNull().toString();

    println("Describe the task: ");
    val description = readlnOrNull().toString();

    val newTask = Task(
        id = getId(file),
        name = name,
        description = description,
        status = Status.PENDING
    )

    saveToJson(newTask, mainFile);
}

fun changeStatus(file: File) {
    val tasks = taskList(file);
    println("Which task to update? (Id): ");
    val choice = readln().toInt();

    val taskToUpdate = tasks.find {it.id == choice}
    if (taskToUpdate != null) {

        println("Editing task: ");
        listTaskById(taskToUpdate.id, mainFile);
        println("Change the status to 1) In progress\n 2) Done\n 3) Stop editing");
        val statusUpdate = readln().toInt();

        when (statusUpdate) {
            1 -> {
                taskToUpdate.status = Status.IN_PROGRESS;
                val updatedData = taskListToJson(tasks);
                file.writeText(updatedData);
                println("Successfully updated the task");
            }
            2 -> {
                taskToUpdate.status = Status.DONE;
                moveTask(doneFile, taskToUpdate);
                deleteTaskById(mainFile, choice);

                println("Successfully updated and moved the task");
            }
            3 -> {
                println("Oki")
            }
            else -> {
                println("Invalid choice")
            }
        }
    }
}