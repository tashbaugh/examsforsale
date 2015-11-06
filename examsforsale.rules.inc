<?php
/**
 * Implements hook_rules_action_info().
 */
function examsforsale_rules_action_info() {
    $actions = array();

    $actions['examsforsale_set_state'] = array(
        'label' => t('Set state for all registrations in an order'),
        'group' => t('Registration'),
        'parameter' => array(
            'commerce_order' => array(
                'type' => 'commerce_order',
                'label' => t('Commerce Order'),
                'description' => t('All registrations on this order will have their state changed.'),
            ),
            'registration_state' => array(
                'type' => 'text',
                'label' => t('Registration State'),
                'description' => t('Registrations will be set to this state.'),
                'options list' => 'registration_get_states_options',
            ),
        ),
    );
    
    return $actions;
}

/**
 * Action callback.
 *
 * Sets all registrations on an order to a given state.
 */
function examsforsale_set_state($order, $registration_state) {
    foreach (entity_metadata_wrapper('commerce_order', $order)->commerce_line_items as $delta => $line_item_wrapper) {
        $display_path = $line_item_wrapper->commerce_display_path->value();
        $url = explode('/', $display_path);
        $registration_id = $url[1];
        $registration = registration_load($registration_id);
        $registration->state = $registration_state;
        registration_save($registration);
    }
}