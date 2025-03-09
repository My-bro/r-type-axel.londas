#!/bin/bash

# Check if FFmpeg is installed
if ! command -v ffmpeg &> /dev/null
then
    echo "FFmpeg could not be found. Please install FFmpeg and try again."
    exit
fi

# Check if the argument is provided
if [ $# -eq 0 ]; then
    echo "No MP4 file provided. Usage: $0 <video.mp4>"
    exit 1
fi

# Get the input video file
input_video=$1

# Extract the base name and extension
video_name=$(basename "$input_video" .mp4)
output_folder="${video_name}_parsed"

# Create the output folder
mkdir -p "$output_folder/frames"

# Extract audio to MP3
ffmpeg -i "$input_video" -q:a 0 -map a "$output_folder/${video_name}.mp3"

# Extract frames as JPEG images
ffmpeg -i "$input_video" "$output_folder/frames/frame_%04d.jpg"

# Get video information using ffprobe
fps=$(ffprobe -v 0 -select_streams v:0 -show_entries stream=r_frame_rate -of csv=p=0 "$input_video")
fps=$(bc -l <<< "$fps")
frame_count=$(ls "$output_folder/frames" | wc -l)
video_format=$(ffprobe -v 0 -select_streams v:0 -show_entries stream=codec_name -of csv=p=0 "$input_video")

# Create a YAML file with video information
cat <<EOL > "$output_folder/info.yml"
video_file: $input_video
frame_count: $frame_count
fps: $fps
format: $video_format
EOL

echo "Processing complete. Check the '$output_folder' directory."
