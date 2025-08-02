"""                    _________               _____ _____
                       __  ____/______ _______ __  /____(_)_______ ____  _______
                       _  /     _  __ \__  __ \_  __/__  / __  __ \_  / / /_  _ \
                       / /___   / /_/ /_  / / // /_  _  /  _  / / // /_/ / /  __/
                       \____/   \____/ /_/ /_/ \__/  /_/   /_/ /_/ \__,_/  \___/

                                 Autocomplete, Edit, Chat, and Agent tutorial
"""


# —————————————————————————————————————————————     Autocomplete     —————————————————————————————————————————————— #
#                            Autocomplete provides inline code suggestions as you type.

# 1. Place cursor after `sorting_algorithm:` below and press [Enter]
# 2. Press [Tab] to accept the Autocomplete suggestion

# Basic assertion for sorting_algorithm:


# —————————————————————————————————————————————————     Edit      ————————————————————————————————————————————————— #
#                   Edit is a convenient way to make quick changes to specific code and files.

# 1. Highlight the code below
# 2. Press [Cmd/Ctrl + I] to Edit
# 3. Try asking Continue to "make this more readable"
def sorting_algorithm(arr):
    """
    Bubble sort implementation that sorts an array in ascending order.

    Args:
        arr: List of comparable elements to be sorted

    Returns:
        The sorted list
    """
    length = len(arr)

    # Iterate through the array
    for i in range(length):
        # Flag to optimize if no swaps occur in a pass
        swapped = False

        # Compare adjacent elements and swap if needed
        for j in range(length - 1):
            if arr[j] > arr[j + 1]:
                # Swap elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        # If no swaps occurred in this pass, array is sorted
        if not swapped:
            break
    return arr

# —————————————————————————————————————————————————     Chat      ————————————————————————————————————————————————— #
#                    Chat makes it easy to ask for help from an LLM without needing to leave the IDE.

# 1. Highlight the code below
# 2. Press [Cmd/Ctrl + L] to add to Chat
# 3. Try asking Continue "what sorting algorithm is this?"
def sorting_algorithm2(x):
    for i in range(len(x)):
        for j in range(len(x) - 1):
            if x[j] > x[j + 1]:
                x[j], x[j + 1] = x[j + 1], x[j]
    return x

# —————————————————————————————————————————————————     Agent      ————————————————————————————————————————————————— #
#           Agent equips the Chat model with the tools needed to handle a wide range of coding tasks, allowing
#           the model to make decisions and save you the work of manually finding context and performing actions.

# 1. Switch from "Chat" to "Agent" mode using the dropdown in the bottom left of the input box
# 2. Try asking Continue "Write unit tests for this code in a new file",
#    or if you have Python installed, "Write unit tests for this code in a new file and run the test"

# ——————————————————      Learn more at https://docs.continue.dev/getting-started/overview      ——————————————————— #