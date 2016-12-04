#pragma once

const char *v_shaders[] = {
"                                                                      \
    uniform vec3 lpos;                                                 \
    uniform vec3 vcol;                                                 \
    varying vec3 light;                                                \
    varying vec3 normal;                                               \
    varying vec3 position;                                             \
    varying vec3 mtlcol;                                               \
    void main() {                                                      \
        normal = gl_NormalMatrix * gl_Normal;                          \
        light = lpos;                                                  \
        mtlcol = vcol;                                                 \
        position = gl_Vertex.xyz;                                      \
        gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;        \
    }                                                                  \
"
};

const char *f_shaders[] = {
"                                                                      \
    varying vec3 light;                                                \
    varying vec3 normal;                                               \
    varying vec3 position;                                             \
    varying vec3 mtlcol;                                               \
    void main() {                                                      \
        float intensity;                                               \
        vec4 color = vec4(mtlcol, 1.0);                                \
        vec3 n = normalize(normal);                                    \
        vec3 l = normalize(position - light).xyz;                      \
        intensity = (floor(dot(l, n) * 80.0) + 1.0) / 80.0;              \
        color *= intensity;                                            \
        gl_FragColor = vec4(color.xyz, 1);                             \
    }                                                                  \
"
};
