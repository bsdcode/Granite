#ifndef MESHLET_RENDER_TYPES_H_
#define MESHLET_RENDER_TYPES_H_

struct AABB
{
	vec3 lo; float pad0; vec3 hi; float pad;
};

struct Bound
{
	vec4 center_radius;
	vec4 cone;
};

struct TaskInfo
{
	uint aabb_instance;
	uint node_instance;
	uint node_count_material_index; // Skinning
	uint mesh_index_count;
};

struct CompactedDrawInfo
{
	uint meshlet_index;
	uint node_offset;
	uint node_count_material_offset;
};

#ifdef MESHLET_RENDER_TASK_HIERARCHICAL
#if MESHLET_RENDER_TASK_HIERARCHICAL
struct CompactedDrawInfoPayload
{
    CompactedDrawInfo infos[32 * 32];
};
#else
struct CompactedDrawInfoPayload
{
    CompactedDrawInfo info;
    uint8_t offsets[32];
};
#endif
#endif

struct IndirectDrawMesh
{
	uint primitive_offset;
	uint vertex_offset;
};

#endif
