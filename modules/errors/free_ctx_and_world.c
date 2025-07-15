#include "../../includes/miniRT.h"

void free_ctx_and_world(t_world *world, t_parse_ctx *ctx)
{
    if (ctx) {
        if (ctx->tmp_object)
            free(ctx->tmp_object);
        if (ctx->line)
            free(ctx->line);
        if (ctx->data)
            ft_free_tab(ctx->data);
    }
    free_world(world);
} 