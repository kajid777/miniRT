/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:54:10 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 18:57:28 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // 仮のライブラリヘッダファイル

// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list *new_list = NULL;
// 	t_list *current = NULL;
// 	t_list *new_elem;
// 	void 	*content;

// 	new_list = NULL;
// 	current = NULL;
// 	while (lst)
// 	{
// 		content = f(lst->content); // 関数 f を適用
// 		new_elem = ft_lstnew(content);// 新しい要素を作成し、リストに追加
// 		if (!new_elem) // メモリ割り当ての失敗を確認
// 		{
// 			ft_lstclear(&new_list, del);// メモリの解放
// 			return (NULL);
// 		}
// 		if (!new_list)
// 			new_list = new_elem;// 新しい要素をリストに追加
// 		else
// 			current->next = new_elem;
// 		current = new_elem;
// 		lst = lst->next;// 次の要素に移動
// 	}
// 	return (new_list);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*new_elem;
	void	*content;

	new_list = NULL;
	current = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_elem = ft_lstnew(content);
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!new_list)
			new_list = new_elem;
		else
			current->next = new_elem;
		current = new_elem;
		lst = lst->next;
	}
	return (new_list);
}
