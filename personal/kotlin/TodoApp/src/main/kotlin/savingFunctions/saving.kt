package todo.savingFunctions
import todo.taskFunctions.*
import java.io.File
import kotlinx.serialization.json.*

fun taskToJson(task: Task): String {
    return """{"id":${task.id},"name":"${task.name}","description":"${task.description}","status":"${task.status}"}"""
}

fun taskListToJson(tasks: List<Task>): String {
    return tasks.joinToString(
        prefix = "[\n",
        postfix = "\n]",
        separator = ",\n"
    ) { task ->
            """{"id":${task.id},"name":"${task.name}","description":"${task.description}","status":"${task.status}"}"""
    }
}

fun jsonToTask(json: String): List<Task> {
    return Json.decodeFromString<List<Task>>(json);
}

fun saveToJson(task: Task, file: File) {
    var data = taskToJson(task);
    
    if (!file.exists() || file.readText().isBlank()) {
        data = "[\n${data}\n]";
        file.writeText(data);
    } else {
        val currentData = file.readText().trim();
        val updatedData = if (currentData.endsWith("]")) {
            currentData.dropLast(1).trimEnd() + ",\n" + data + "\n]";
        } else {
            "[\n$data\n]";
        }
        file.writeText(updatedData);
    }
}