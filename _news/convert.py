import os
import re

# Directory containing the *.mdwn files
directory = '/var/home/jimmac/src/git/cairographics.org/_news'

# Regular expression pattern to match the old header
header_pattern = r'\[\[!meta title="(.+?)"\]\]\n\[\[!meta date="(.+?)"\]\]'

# Loop through files in the directory
for filename in os.listdir(directory):
    if filename.endswith('.mdwn'):
        with open(os.path.join(directory, filename), 'r') as file:
            content = file.read()

        # Replace the old header with Jekyll frontmatter
        content = re.sub(header_pattern, r'---\ntitle: \1\ndate: \2\n---', content)

        with open(os.path.join(directory, filename), 'w') as file:
            file.write(content)
        print(f"Updated {filename}")

print("Conversion completed.")

