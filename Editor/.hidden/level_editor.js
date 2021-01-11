let enemyPresets = ["Pirate", "Gunner"];


function scopedUniqueId()
{
    var internalIdCounter = 0;
    return function()
    {
        return "uid_" + internalIdCounter++;
    }
}
var uniqueId = scopedUniqueId();

function presetChange(e)
{
    document.getElementById("input-type").value = e.target.value;
}

function clearParameters()
{
    document.getElementById("input-type").value = "";
    document.getElementById("input-x").value = 0;
    document.getElementById("input-y").value = 0;
    document.getElementById("input-timer").value = 0;
}

createEnemy();
function createEnemy()
{
    data = {};
    data.type = document.getElementById("input-type").value;
    data.pos = {};
    data.pos.x = ~~document.getElementById("input-x").value;
    data.pos.y = ~~document.getElementById("input-y").value;
    data.timer = ~~document.getElementById("input-timer").value;

    if (data.type == "")
    {
        data.type = "Enemy";
    }

    let enemyBox = document.createElement("div");
    enemyBox.setAttribute("draggable", "true");
    enemyBox.addEventListener("dragstart", handleDragStart, false);
    enemyBox.addEventListener("dragend", handleDragEnd, false);
    enemyBox.innerHTML = `
        <table>
            <tr>
                <th>Type</th>
                <th>Position</th>
                <th>Timer</th>
            </tr>
            <tr>
                <td>${data.type}</td>
                <td>{${data.pos.x}, ${data.pos.y}}</td>
                <td>${data.timer}ms</td>
            </tr>
        </table>
    `;

    enemyBox.classList.add("enemy-box");
    let spawner = document.getElementById("enemy-spawner");
    spawner.innerHTML = "";
    spawner.appendChild(enemyBox);

    console.log(data);
}

function addPackListeners(pack)
{
    pack.id = uniqueId();
    pack.addEventListener("dragenter", handleDragEnter, false);
    pack.addEventListener("dragleave", handleDragLeave, false);
}

document.querySelectorAll(".pack").forEach(function(pack) {
    addPackListeners(pack);
})

let drag = { active: true, id: undefined, parent: undefined };
// Enemy-Box
function handleDragStart(e)
{
    if (drag.active) return false;
    drag.active = true;

    drag.parent = this.parentNode;
    console.log(drag);

    this.style.opacity = 0.4;
}
// Enemy-Box
function handleDragEnd(e)
{
    this.style.opacity = 1;
    drag.active = false;

    console.log(drag);

    // Handle "drop"
    if (drag.id)
    {
        document.getElementById(drag.id).appendChild(this);
    }
}

// Pack
function handleDragEnter(e)
{
    this.classList.add("drag-over");
    drag.id = this.id;
}
// Pack
function handleDragLeave(e)
{
    this.classList.remove("drag-over");
}