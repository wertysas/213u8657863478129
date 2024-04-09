import pytest
import subprocess
import os

#EXECUTABLE_PATH = "@toybot_EXECUTABLE_PATH@"
CWD = os.getcwd()
EXECUTABLE_PATH = CWD + "/../cmake-build-release/src/toybot"
INPUT_DIR = CWD+"/test_inputs"
OUTPUT_DIR = CWD+"/expected_outputs"
print(EXECUTABLE_PATH)


def load_inputs():
    inputs = os.listdir(INPUT_DIR)
    io_pairs = []
    for input_file in inputs:
        with open(os.path.join(OUTPUT_DIR, input_file), 'r') as f:
            input_path = os.path.join(INPUT_DIR, input_file)
            expected_output = f.read()
            io_pairs.append((input_path, expected_output))
    return io_pairs


@pytest.mark.parametrize("input_file, expected_output", load_inputs())
def test_toybot(input_file, expected_output):
    with open(input_file) as f:
        result = subprocess.run([EXECUTABLE_PATH], stdin=f, capture_output=True, text=True)
        if "error" in os.path.basename(input_file):
            assert result.stderr == expected_output
        else:
            assert result.stdout == expected_output

