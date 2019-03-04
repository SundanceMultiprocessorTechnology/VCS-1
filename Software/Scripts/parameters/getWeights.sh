#! /bin/bash
cd parameters
wget https://p-ams1.pcloud.com/cBZLX4vlJZ4MWHDLZdy93ZZTPeVA7Z2ZZgoRZkZbxCGYZCXZ67ZX0Zn0ZAVZ7kZqZvkZV7ZakZH7ZuXZj0Zh0ZIspq7ZkcxkO6dQ8kBx3PhliUhkjQj4xSb7/yolov3.weights
cd ..
echo "parameters/yolov3.weights" > .gitignore
